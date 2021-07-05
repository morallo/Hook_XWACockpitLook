#include "cockpitlook.h"
#include "SharedMem.h"
#include "OpenXR.h"
#include <VRRendererOpenXR.h>

void log_debug(const char* format, ...);
extern SharedMem g_SharedMem;


// Put the address of g_hmdPose in shared memory. We only need to do this once.
// Setting bDataReady to true means that pDataPtr has been initialized to a valid
// address.
SharedData* pSharedData = (SharedData*)g_SharedMem.GetMemoryPtr();

bool GetOpenXRTrackingData(float* yaw, float* pitch, float* x, float* y, float* z)
{
	StereoRenderer* stereoRenderer = new VRRendererOpenXR();
	// Call the function to get the poses in ddraw.dll
	stereoRenderer->UpdateViewMatrices();
	*x = stereoRenderer->x;
	*y = stereoRenderer->y;
	*z = stereoRenderer->z;
	*pitch = stereoRenderer->pitch;
	*yaw = stereoRenderer->yaw;

	return true;
}
