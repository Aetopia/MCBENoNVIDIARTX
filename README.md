# MCBENoNVIDIARTX
Disables Raytracing (DirectX Raytracing) within Minecraft's NVIDIA Driver Profile.

## Intentions of rewriting the original project.
1. Removal of checking for an RTX card since altering the value for a non-RTX graphics card doesn't do anything.
2. Cleaner error handling by clubing similar functions under a single `if` statement.
3. Using C instead of C++, makes things cleaner and simpler.
4. Giving a clear description of the project exactly does.
5. Allowing the user to toggle on or off `Raytracing - (DXR)` via a `MessageBox`.

## What does the project exactly do?
This project disables the following setting `Raytracing - (DXR)` within Minecraft Bedrock Edition's NVIDIA Driver Profile.  
Disabling this option makes Minecraft detects the system to have a Non-RTX capable NVIDIA GPU.       
Making the game's engine swap from using `DX12 RTX` to `DX12`.     
Resolving this issue: https://bugs.mojang.com/browse/MCPE-161517    

> Notes: 
> 1. You can also disable Raytracing - (DXR) using the [NVIDIA Profile Inspector](https://github.com/Orbmu2k/nvidiaProfileInspector) also.
> 2. To disable RTX for Minecraft Preview, you will need to disable it in the global profile & not the application specific profile.
> 3. You need administrator permissions to alter `Raytracing - (DXR)`.

# Download
Fetch the latest release from [GitHub Releases](https://github.com/Aetopia/MCBENoNVIDIARTX/releases).

# Build
1. Open the Solution file in the latest version of Visual Studio.
2. Build the Solution.
