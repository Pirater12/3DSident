#include "mcu.h"

Result mcuInit()
{
    return srvGetServiceHandle(&mcuhwcHandle, "mcu::HWC");
}

Result mcuExit()
{
    return svcCloseHandle(mcuhwcHandle);
}

Result mcuGetBatteryLevel(u8* out)
{
    u32* ipc = getThreadCommandBuffer();
    ipc[0] = 0x50000;
    Result ret = svcSendSyncRequest(mcuhwcHandle);
    if(ret < 0) return ret;
	*out = ipc[2];
    return ipc[1];
}

Result mcuGetBatteryVoltage(u8* out)
{
    u32* ipc = getThreadCommandBuffer();
    ipc[0] = 0x40000;
    Result ret = svcSendSyncRequest(mcuhwcHandle);
    if(ret < 0) return ret;
	*out = ipc[2];
    return ipc[1];
}

Result mcuGetVolume(u8* out)
{
    u32* ipc = getThreadCommandBuffer();
    ipc[0] = 0xB0000;
    Result ret = svcSendSyncRequest(mcuhwcHandle);
    if(ret < 0) return ret;
	*out = ipc[2];
    return ipc[1];
}