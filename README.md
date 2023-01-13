# MCBENoNVIDIARTX
Disables Raytracing (DirectX Raytracing) within Minecraft's NVIDIA Driver Profile.

## What does the project exactly do?
This project disables the following setting `Raytracing - (DXR)` within Minecraft Bedrock Edition's NVIDIA Driver Profile.  
Disabling this option makes Minecraft detects the system to have a Non-RTX capable NVIDIA GPU.       
Making the game's engine swap from using `DX12 RTX` to `DX12`.     
Resolving this issue: https://bugs.mojang.com/browse/MCPE-161517    

**Note: You can also disable Raytracing - (DXR) using the [NVIDIA Profile Inspector](https://github.com/Orbmu2k/nvidiaProfileInspector) also.**
**Additionally to disable RTX for Minecraft Preview, you will need to disable it in the global profile not the application specific profile.**

# Download
Fetch the latest release from [GitHub Releases](https://github.com/Aetopia/MCBENoNVIDIARTX/releases).

# Build
1. Open the Solution file in the latest version of Visual Studio.
2. Build the Solution.
