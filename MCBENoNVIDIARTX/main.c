#pragma comment(lib, "nvapi/amd64/nvapi64.lib")
#include <Windows.h>
#include <nvapi.h>
#include <stdio.h>

int main() {
	NvDRSSessionHandle hSession;
	NvDRSProfileHandle hProfile;
	NVDRS_SETTING sDXRaytracing = {
		.version = NVDRS_SETTING_VER,
		.settingId = 0x00DE429A,
		.settingType = NVDRS_DWORD_TYPE };
	HWND hwnd = GetConsoleWindow();
	int ID = MessageBox(hwnd, L"Click [Yes] to Enable.\nClick [No] to Disable.", L"Configure Raytracing - (DXR) for Minecraft", MB_YESNOCANCEL);
	LPCWSTR msg = 0;

	// Initialize the NVIDIA API.
	if (NvAPI_Initialize() ||
		NvAPI_DRS_CreateSession(&hSession) ||
		NvAPI_DRS_LoadSettings(hSession) ||
		NvAPI_DRS_FindProfileByName(hSession, L"Minecraft", &hProfile)) {
		MessageBox(hwnd, L"Failed to initialize NvAPI!", L"Error", MB_ICONERROR);
		return 1;
	};

	/*
	0x00DE429A points to Raytracing - (DXR) in the driver profile.
	You can see setting ID for this by using NVIDIA Profile Inspector's Developer Mode in the "Minecraft" Profile.
	*/
	switch (ID) {
	case IDYES:
		msg = L"Raytracing Enabled!\0";
		sDXRaytracing.u32CurrentValue = 1;
		break;
	case IDNO:
		msg = L"Raytracing Disabled!\0";
		sDXRaytracing.u32CurrentValue = 0;
	};
	if (ID != IDCANCEL) {
		if (NvAPI_DRS_SetSetting(hSession, hProfile, &sDXRaytracing)) {
			MessageBox(hwnd, L"Failed to set Raytracing - (DXR)!", L"Error", MB_ICONERROR);
			return 1;
		};
		MessageBox(hwnd, msg, L"Success", MB_ICONINFORMATION);
	};

	// Cleanup.
	NvAPI_DRS_SaveSettings(hSession);
	NvAPI_DRS_DestroySession(hSession);
	NvAPI_Unload();
	return 0;
}