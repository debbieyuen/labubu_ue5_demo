#!/bin/bash

echo "Updating system..."
sudo apt update

echo "Installing Mosquitto broker and clients..."
sudo apt install -y mosquitto mosquitto-clients

echo "Enabling Mosquitto service..."
sudo systemctl enable mosquitto

echo "Starting Mosquitto service..."
sudo systemctl start mosquitto

echo "MQTT setup complete"
systemctl status mosquitto --no-pager

# On the Raspberry Pi 5 include the above or this file
# Make it excutable with: chmod +x setup_mqtt.sh
# Run it: ./setup_mqtt.sh
# Verifty it: systemctl status mosquitto
# Result: Active: active (running)