# The Labubu Twins

A hardware-software digital twins concept, Labubu Twin. Labubu Twin explores three-way communication between the user, the digital Labubu, and the physical robotic Labubu. Presenting at SIGGRAPH Asia in December 2025. 

Digital Labubu (UE5.6)            |  Physical Labubu (Raspberry Pi 5)A
:-------------------------:|:-------------------------:
<img width="844" height="449" alt="Screenshot 2025-09-15 at 12 08 38 PM" src="https://github.com/user-attachments/assets/bd30eb41-ae50-49d7-888f-5155980b4dc0" />  |  <img width="628" height="469" alt="Screenshot 2025-09-15 at 12 08 23 PM" src="https://github.com/user-attachments/assets/84a30351-7a3d-470d-bce5-e63d307ab820" />




![DT-DSC_1036](https://github.com/user-attachments/assets/a0b9a71d-995b-4a0c-a316-1f6078283614)

## Requirements
### Software
* Unreal Engine 5.6.1
* Epic Games Launcher
* Windows computer (MetaHuman Creator is not compatible with MacOS and there is no longer an updated web version)
* All MetaHuman Plugins (requires Engine restart)
* UE MQTT Plugin
* Blender
* JetBrains Rider IDE

### Hardware
* Raspberry Pi 5 (8 GB, preferably 16GB)
* 650W power supply unit (PSU) for the eGPU
* Raspberry Pi 5 M.2 hat
* OccuLink cable for high-bandwidth PCIe connectivity
* External GPU stand
* AMD Sapphire NITRO+ Radeon RX 6600 XT 8GB
* SSD or MicroSD (at least UHS-I U3 / V30 speed class or higher)
* Heatsink or fan for cooling

## Setup 

**Step 1:** Install the [Epic Games Launcher](https://store.epicgames.com/en-US/download) and then install engine version [5.6.1](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-5-6-release-notes). 

**Step 2:** Once you have completed the installation process for Unreal Engine, under the `Library` tab, click on the arrow button within the yellow `Launch` button. Select `Options` and then enable *MetaHuman Creator Core Data*. 

**Step 3:** You may either start with a blank project or fork this repository. If you are creating a blank project, we will be starting with the *3rd Person* template, which includes rigged humanoid characters by default. If you are interested in cloning our sample project you may run the following commands:

First, make sure [GitLFS](https://git-lfs.com) is installed. You may then check to make sure it is installed correctly and working in your directory folder by running: 
```
git lfs install
```
Next, clone the repository
```
git clone https://github.com/debbieyuen/labubu_ue5
```

**Step 4:** Install all the Metahuman plugins and restart the Editor. Once your Engine has successfully restarted, navigate to your *Conent Browser* and select `MetaHuman/`.
