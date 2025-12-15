// Fill out your copyright notice in the Description page of Project Settings.

#include "MQTTManager.h"
#include "Async/Async.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "MQTTClient.h"

#define ADDRESS     "tcp://127.0.0.1:1883"
#define CLIENTID    "UnrealMQTTClient"
#define TOPIC       "siggraph/pi/state"
#define QOS         1
#define TIMEOUT     10000L

AMQTTManager::AMQTTManager()
{
    PrimaryActorTick.bCanEverTick = false;
    Client = nullptr;
}

void AMQTTManager::BeginPlay()
{
    Super::BeginPlay();
    ConnectMQTT();
}

void AMQTTManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (Client)
    {
        MQTTClient_disconnect(Client, 1000);
        MQTTClient_destroy(&Client);
    }
    Super::EndPlay(EndPlayReason);
}

void AMQTTManager::ConnectMQTT()
{
    MQTTClient_create(&Client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, nullptr);

    MQTTClient_setCallbacks(Client, this, nullptr, OnMessageArrived, nullptr);

    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.keepAliveInterval = 60;
    conn_opts.cleansession = 1;

    int rc = MQTTClient_connect(Client, &conn_opts);
    if (rc != MQTTCLIENT_SUCCESS)
    {
        UE_LOG(LogTemp, Error, TEXT("MQTT connect failed: %d"), rc);
        return;
    }

    MQTTClient_subscribe(Client, TOPIC, QOS);
    UE_LOG(LogTemp, Log, TEXT("MQTT connected and subscribed"));
}

int AMQTTManager::OnMessageArrived(
    void* context,
    char* topicName,
    int topicLen,
    MQTTClient_message* message)
{
    AMQTTManager* Self = static_cast<AMQTTManager*>(context);

    FString Payload(
        UTF8_TO_TCHAR(static_cast<char*>(message->payload))
    );

    AsyncTask(ENamedThreads::GameThread, [Self, Payload]()
    {
        Self->HandleMessage(Payload);
    });

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void AMQTTManager::HandleMessage(const FString& Payload)
{
    TSharedPtr<FJsonObject> Json;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Payload);

    if (!FJsonSerializer::Deserialize(Reader, Json))
        return;

    CurrentPiState.timestamp = Json->GetNumberField("timestamp");
    CurrentPiState.dialogue = Json->GetStringField("dialogue");
    CurrentPiState.app_state = Json->GetStringField("app_state");

    CurrentPiState.arm_pos_x = Json->GetNumberField("arm_pos_x");
    CurrentPiState.arm_pos_y = Json->GetNumberField("arm_pos_y");
    CurrentPiState.arm_pos_z = Json->GetNumberField("arm_pos_z");

    CurrentPiState.arm_rot_pitch = Json->GetNumberField("arm_rot_pitch");
    CurrentPiState.arm_rot_yaw = Json->GetNumberField("arm_rot_yaw");
    CurrentPiState.arm_rot_roll = Json->GetNumberField("arm_rot_roll");

    CurrentPiState.head_pos_x = Json->GetNumberField("head_pos_x");
    CurrentPiState.head_pos_y = Json->GetNumberField("head_pos_y");
    CurrentPiState.head_pos_z = Json->GetNumberField("head_pos_z");

    CurrentPiState.head_rot_pitch = Json->GetNumberField("head_rot_pitch");
    CurrentPiState.head_rot_yaw = Json->GetNumberField("head_rot_yaw");
    CurrentPiState.head_rot_roll = Json->GetNumberField("head_rot_roll");

    CurrentPiState.eyes_open = Json->GetBoolField("eyes_open");
    CurrentPiState.audio_level = Json->GetNumberField("audio_level");
    CurrentPiState.is_speaking = Json->GetBoolField("is_speaking");
}


