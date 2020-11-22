#pragma once
#include <headers/openvr.h>
#include "cockpitlook.h"

bool InitSteamVR();
void ShutdownSteamVR();
bool GetSteamVRPositionalData(float *yaw, float *pitch, float *x, float *y, float *z);
extern bool __declspec(dllexport) GetLastSteamVRPose(vr::TrackedDevicePose_t* trackedDevicePose);