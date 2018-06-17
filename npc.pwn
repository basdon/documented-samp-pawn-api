
#include <a_npc>

main()
{
	new Float:f = 0.0
	new i

	print ""
	printf ""
	format "", i, ""
	SetTimer "", i, i
	KillTimer i
	GetTickCount
	asin f
	acos f
	atan f
	atan2 f, f
	SendChat ""
	SendCommand ""
	GetPlayerState i
	GetPlayerPos i, f, f, f
	GetPlayerVehicleID i
	GetPlayerArmedWeapon i
	GetPlayerHealth i, f
	GetPlayerArmour i
	GetPlayerSpecialAction i
	IsPlayerStreamedIn i
	IsVehicleStreamedIn i
	GetPlayerKeys i, i, i, i
	GetPlayerFacingAngle i, f
	GetMyPos f, f, f
	SetMyPos f, f, f
	GetMyFacingAngle f
	SetMyFacingAngle f
	GetDistanceFromMeToPoint f, f, f, f
	IsPlayerInRangeOfPoint i, f, f, f, f
	GetPlayerName i, "", i
	IsPlayerConnected i
	StartRecordingPlayback i, ""
	StopRecordingPlayback
	PauseRecordingPlayback
	ResumeRecordingPlayback
	OnNPCModeInit
	OnNPCModeExit
	OnNPCConnect i
	OnNPCDisconnect ""
	OnNPCSpawn
	OnNPCEnterVehicle i, i
	OnNPCExitVehicle
	OnClientMessage i, ""
	OnPlayerDeath i
	OnPlayerText i, ""
	OnPlayerStreamIn i
	OnPlayerStreamOut i
	OnVehicleStreamIn i
	OnVehicleStreamOut i
	OnRecordingPlaybackEnd
}

