
#include <a_samp>
#include <a_http>

main()
{
	new Float:f = 0.0
	new i
	AddMenuItem Menu:0, 0, ""
	AddPlayerClass 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0
	AddPlayerClassEx 0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0
	AddStaticPickup 0, 0, 0.0, 0.0, 0.0, 0
	AddStaticVehicle 0, 0.0, 0.0, 0.0, 0.0, 0, 0
	AddStaticVehicleEx 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0
	AddVehicleComponent 0, 0
	AllowAdminTeleport 0
	AllowPlayerTeleport 0, 0
	ApplyActorAnimation 0, "", "", 0.0, 0, 0, 0, 0, 0
	ApplyAnimation 0, "", "", 0.0, 0, 0, 0, 0, 0, 0
	acos 0.0
	asin 0.0
	atan 0.0
	atan2 0.0, 0.0
	Attach3DTextLabelToPlayer Text3D:0, 0, 0.0, 0.0, 0.0
	Attach3DTextLabelToVehicle Text3D:0, 0, 0.0, 0.0, 0.0
	AttachCameraToObject 0, 0
	AttachCameraToPlayerObject 0, 0
	AttachObjectToObject 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	AttachObjectToPlayer 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	AttachObjectToVehicle 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	AttachPlayerObjectToPlayer 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	AttachPlayerObjectToVehicle 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	AttachTrailerToVehicle 0, 0
	Ban 0
	BanEx 0, ""
	BlockIpAddress "", 0
	CallLocalFunction "", "", 0
	CallRemoteFunction "", "", 0
	CancelEdit 0
	CancelSelectTextDraw 0
	ChangeVehicleColor 0, 0, 0
	ChangeVehiclePaintjob 0, 0
	clamp 0
	ClearActorAnimations 0
	ClearAnimations 0
	ConnectNPC "", ""
	Create3DTextLabel "", 0, 0.0, 0.0, 0.0, 0.0, 0, 0
	CreateActor 0, 0.0, 0.0, 0.0, 0.0
	CreateExplosion 0.0, 0.0, 0.0, 0, 0.0
	CreateExplosionForPlayer 0, 0.0, 0.0, 0.0, 0, 0.0
	CreateMenu "", 1, 0.0, 0.0, 0.0, 0.0
	CreateObject 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	CreatePickup 0, 0, 0.0, 0.0, 0.0, 0
	CreatePlayer3DTextLabel 0, "", 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0
	CreatePlayerObject 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
	CreatePlayerTextDraw 0, 0.0, 0.0, ""
	CreateVehicle 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0
	db_open ""
	db_close DB:0
	db_query DB:0, ""
	db_free_result DBResult:0
	db_num_rows DBResult:0
	db_next_row DBResult:0
	db_num_fields DBResult:0
	db_field_name DBResult:0, 0, "", 0
	db_get_field DBResult:0, 0, "", 0
	db_get_field_int DBResult: 0, 0
	db_get_field_float DBResult:0, 0
	db_get_field_assoc DBResult:0, "", "", 0
	db_get_field_assoc_int DBResult:0, ""
	db_get_field_assoc_float DBResult:0, ""
	db_get_mem_handle DB:0
	db_get_result_mem_handle DBResult:0
	db_debug_openfiles
	db_debug_openresults
	Delete3DTextLabel Text3D:0
	DeletePVar 0, ""
	DeletePlayer3DTextLabel 0, PlayerText3D:0
	DeleteSVar ""
	deleteproperty
	DestroyActor 0
	DestroyMenu Menu:0
	DestroyObject 0
	DestroyPickup 0
	DestroyPlayerObject 0, 0
	DestroyVehicle 0
	DetachTrailerFromVehicle 0
	DisableInteriorEnterExits
	DisableMenu Menu:0
	DisableMenuRow Menu:0, 0
	DisableNameTagLOS
	DisablePlayerCheckpoint 0
	DisablePlayerRaceCheckpoint 0
	DisableRemoteVehicleCollisions 0, 0
	EditAttachedObject 0, 0
	EditObject 0, 0
	EditPlayerObject 0, 0
	EnablePlayerCameraTarget 0, 0
	EnableStuntBonusForAll 0
	EnableStuntBonusForPlayer 0, 0
	EnableTirePopping 0
	EnableVehicleFriendlyFire
	EnableZoneNames 0
	existproperty
	fblockread File:0, ""
	fblockwrite File:0, ""
	fclose File:0
	fexist ""
	fgetchar File:0, 0
	flength File:0
	float 0
	floatabs 0.0
	floatcos 0.0
	floatfract 0.0
	floatlog 0.0
	floatpower 0.0, 0.0
	floatround 0.0
	floatsin 0.0
	floatsqroot 0.0
	floatstr ""
	floattan 0.0
	fmatch "", ""
	fopen ""
	ForceClassSelection 0
	format "", 0, ""
	fputchar File:0, 0
	fread File:0, ""
	fremove ""
	fseek File:0
	ftemp
	funcidx ""
	fwrite File:0, ""
	GameModeExit
	GameTextForAll "", 0, 0
	GameTextForPlayer 0, "", 0, 0
	GangZoneCreate 0.0, 0.0, 0.0, 0.0
	GangZoneDestroy 0
	GangZoneFlashForAll 0, 0
	GangZoneFlashForPlayer 0, 0, 0
	GangZoneHideForAll 0
	GangZoneHideForPlayer 0, 0
	GangZoneShowForAll 0, 0
	GangZoneShowForPlayer 0, 0, 0
	GangZoneStopFlashForAll 0
	GangZoneStopFlashForPlayer 0, 0
	GetActorFacingAngle 0, f
	GetActorHealth 0, f
	GetActorPoolSize
	GetActorPos 0, f, f, f
	GetActorVirtualWorld 0
	GetAnimationName 0, "", 0, "", 0
	GetConsoleVarAsBool ""
	GetConsoleVarAsInt ""
	GetConsoleVarAsString "", "", 0
	GetGravity
	GetMaxPlayers
	GetNetworkStats "", 0
	GetObjectModel 0
	GetObjectPos 0, f, f, f
	GetObjectRot 0, f, f, f
	GetPVarFloat 0, ""
	GetPVarInt 0, ""
	GetPVarNameAtIndex 0, 0, "", 0
	GetPVarString 0, "", "", 0
	GetPVarType 0, ""
	GetPVarsUpperIndex 0
	GetPlayerAmmo 0
	GetPlayerAnimationIndex 0
	GetPlayerArmour 0, f
	GetPlayerCameraAspectRatio 0
	GetPlayerCameraFrontVector 0, f, f, f
	GetPlayerCameraMode 0
	GetPlayerCameraPos 0, f, f, f
	GetPlayerCameraTargetActor 0
	GetPlayerCameraTargetObject 0
	GetPlayerCameraTargetPlayer 0
	GetPlayerCameraTargetVehicle 0
	GetPlayerCameraZoom 0
	GetPlayerColor 0
	GetPlayerDistanceFromPoint 0, f, f, f
	GetPlayerDrunkLevel 0
	GetPlayerFacingAngle 0, f
	GetPlayerFightingStyle 0
	GetPlayerHealth 0, f
	GetPlayerIp 0, "", 0
	GetPlayerInterior 0
	GetPlayerKeys 0, i, i, i
	GetPlayerLastShotVectors 0, f, f, f, f, f, f
	GetPlayerMenu 0
	GetPlayerMoney 0
	GetPlayerName 0, "", 0
	GetPlayerNetworkStats 0, "", 0
	GetPlayerObjectModel 0, 0
	GetPlayerObjectPos 0, 0, f, f, f
	GetPlayerObjectRot 0, 0, f, f, f
	GetPlayerPing 0
	GetPlayerPoolSize
	GetPlayerPos 0, f, f, f
	GetPlayerScore 0
	GetPlayerSkin 0
	GetPlayerSpecialAction 0
	GetPlayerState 0
	GetPlayerSurfingObjectID 0
	GetPlayerSurfingVehicleID 0
	GetPlayerTargetActor 0
	GetPlayerTargetPlayer 0
	GetPlayerTeam 0
	GetPlayerTime 0, i, i
	GetPlayerVehicleID 0
	GetPlayerVehicleSeat 0
	GetPlayerVelocity 0, f, f, f
	GetPlayerVersion 0, "", 0
	GetPlayerVirtualWorld 0
	GetPlayerWantedLevel 0
	GetPlayerWeapon 0
	GetPlayerWeaponData 0, 0, i, i
	GetPlayerWeaponState 0
	GetSVarFloat ""
	GetSVarInt ""
	GetSVarNameAtIndex 0, "", 0
	GetSVarString "", "", 0
	GetSVarType ""
	GetSVarsUpperIndex
	GetServerTickRate
	GetServerVarAsBool ""
	GetServerVarAsInt ""
	GetServerVarAsString "", "", 0
	GetTickCount
	GetVehicleComponentInSlot 0, 0
	GetVehicleComponentType 0
	GetVehicleDamageStatus 0, i, i, i, i
	GetVehicleDistanceFromPoint 0, f, f, f
	GetVehicleHealth 0, f
	GetVehicleModel 0
	GetVehicleModelInfo 0, 0, f, f, f
	GetVehicleParamsCarDoors 0, i, i, i, i
	GetVehicleParamsCarWindows 0, i, i, i, i
	GetVehicleParamsEx 0, i, i, i, i, i, i, i
	GetVehicleParamsSirenState 0
	GetVehiclePoolSize
	GetVehiclePos 0, f, f, f
	GetVehicleRotationQuat 0, f, f, f, f
	GetVehicleTrailer 0
	GetVehicleVelocity 0, f, f, f
	GetVehicleVirtualWorld 0
	GetVehicleZAngle 0, f
	GetWeaponName 0, "", 0
	getarg 0
	getdate
	getproperty
	gettime
	GivePlayerMoney 0, 0
	GivePlayerWeapon 0, 0, 0
	gpci 0, "", 0
	HTTP 0, 0, "", "", ""
	heapspace
	HideMenuForPlayer Menu:0, 0
	InterpolateCameraLookAt 0, f, f, f, f, f, f, 0
	InterpolateCameraPos 0, f, f, f, f, f, f, 0
	IsActorInvulnerable 0
	IsActorStreamedIn 0, 0
	IsObjectMoving 0
	IsPlayerAdmin 0
	IsPlayerAttachedObjectSlotUsed 0, 0
	IsPlayerConnected 0
	IsPlayerInAnyVehicle 0
	IsPlayerInCheckpoint 0
	IsPlayerInRaceCheckpoint 0
	IsPlayerInRangeOfPoint 0, f, f, f, f
	IsPlayerInVehicle 0, 0
	IsPlayerNPC 0
	IsPlayerObjectMoving 0, 0
	IsPlayerStreamedIn 0, 0
	IsTrailerAttachedToVehicle 0
	IsValidActor 0
	IsValidMenu Menu:0
	IsValidObject 0
	IsValidPlayerObject 0, 0
	IsValidVehicle 0
	IsVehicleStreamedIn 0, 0
	ispacked ""
	Kick 0
	KillTimer 0
	LimitGlobalChatRadius f
	LimitPlayerMarkerRadius f
	LinkVehicleToInterior 0, 0
	ManualVehicleEngineAndLights
	memcpy "", "", 0, 0, 0
	MoveObject 0, f, f, f, f
	MovePlayerObject 0, 0, f, f, f, f
	NetStats_BytesReceived 0
	NetStats_BytesSent 0
	NetStats_ConnectionStatus 0
	NetStats_GetConnectedTime 0
	NetStats_GetIpPort 0, "", 0
	NetStats_MessagesReceived 0
	NetStats_MessagesRecvPerSecond 0
	NetStats_MessagesSent 0
	NetStats_PacketLossPercent 0
	numargs
	PlayAudioStreamForPlayer 0, ""
	PlayCrimeReportForPlayer 0, 0, 0
	PlayerPlaySound 0, 0, f, f, f
	PlayerSpectatePlayer 0, 0
	PlayerSpectateVehicle 0, 0
	PlayerTextDrawDestroy 0, PlayerText:0
	PlayerTextDrawLetterSize 0, PlayerText:0, f, f
	PlayerTextDrawTextSize 0, PlayerText:0, f, f
	PlayerTextDrawAlignment 0, PlayerText:0, 0
	PlayerTextDrawColor 0, PlayerText:0, 0
	PlayerTextDrawUseBox 0, PlayerText:0, 0
	PlayerTextDrawBoxColor 0, PlayerText:0, 0
	PlayerTextDrawSetShadow 0, PlayerText:0, 0
	PlayerTextDrawSetOutline 0, PlayerText:0, 0
	PlayerTextDrawBackgroundColor 0, PlayerText:0, 0
	PlayerTextDrawFont 0, PlayerText:0, 0
	PlayerTextDrawSetProportional 0, PlayerText:0, 0
	PlayerTextDrawSetSelectable 0, PlayerText:0, 0
	PlayerTextDrawShow 0, PlayerText:0
	PlayerTextDrawHide 0, PlayerText:0
	PlayerTextDrawSetString 0, PlayerText:0, ""
	PlayerTextDrawSetPreviewModel 0, PlayerText:0, 0
	PlayerTextDrawSetPreviewRot 0, PlayerText:0, f, f, f, f
	PlayerTextDrawSetPreviewVehCol 0, PlayerText:0, 0, 0
	print ""
	printf ""
	PutPlayerInVehicle 0, 0, 0
	random 0
	RemoveBuildingForPlayer 0, 0, f, f, f, f
	RemovePlayerAttachedObject 0, 0
	RemovePlayerFromVehicle 0
	RemovePlayerMapIcon 0, 0
	RemoveVehicleComponent 0, 0
	RepairVehicle 0
	ResetPlayerMoney 0
	ResetPlayerWeapons 0
	SHA256_PassHash "", "", "", 0
	SelectObject 0
	SelectTextDraw 0, 0
	SendClientMessage 0, 0, ""
	SendClientMessageToAll 0, ""
	SendDeathMessage 0, 0, 0
	SendDeathMessageToPlayer 0, 0, 0, 0
	SendPlayerMessageToPlayer 0, 0, ""
	SendPlayerMessageToAll 0, ""
	SendRconCommand ""
	SetActorFacingAngle 0, f
	SetActorHealth 0, f
	SetActorInvulnerable 0, 0
	SetActorPos 0, f, f, f
	SetActorVirtualWorld 0, 0
	SetCameraBehindPlayer 0
	SetDeathDropAmount 0
	SetGameModeText ""
	SetGravity f
	SetMenuColumnHeader Menu:0, 0, ""
	SetNameTagDrawDistance f
	SetObjectMaterial 0, 0, 0, "", "", 0
	SetObjectMaterialText 0, ""
	SetObjectNoCameraCol 0
	SetObjectPos 0, f, f, f
	SetObjectRot 0, f, f, f
	SetObjectsDefaultCameraCol 0
	SetPVarFloat 0, "", f
	SetPVarInt 0, "", 0
	SetPVarString 0, "", ""
	SetPlayerAmmo 0, 0, 0
	SetPlayerArmedWeapon 0, 0
	SetPlayerArmour 0, f
	SetPlayerAttachedObject 0, 0, 0, 0
	SetPlayerCameraLookAt 0, f, f, f
	SetPlayerCameraPos 0, f, f, f
	SetPlayerChatBubble 0, "", 0, f, 0
	SetPlayerCheckpoint 0, f, f, f, f
	SetPlayerDrunkLevel 0, 0
	SetPlayerFacingAngle 0, f
	SetPlayerFightingStyle 0, 0
	SetPlayerHealth 0, f
	SetPlayerInterior 0, 0
	SetPlayerMapIcon 0, 0, f, f, f, 0, 0, 0
	SetPlayerName 0, ""
	SetPlayerObjectMaterial 0, 0, 0, 0, "", "", 0
	SetPlayerObjectMaterialText 0, 0, ""
	SetPlayerObjectNoCameraCol 0, 0
	SetPlayerObjectPos 0, 0, f, f, f
	SetPlayerObjectRot 0, 0, f, f, f
	SetPlayerPos 0, f, f, f
	SetPlayerPosFindZ 0, f, f, f
	SetPlayerRaceCheckpoint 0, 0, f, f, f, f, f, f, f
	SetPlayerScore 0, 0
	SetPlayerShopName 0, ""
	SetPlayerSkillLevel 0, 0, 0
	SetPlayerSkin 0, 0
	SetPlayerSpecialAction 0, 0
	SetPlayerTeam 0, 0
	SetPlayerTime 0, 0, 0
	SetPlayerVelocity 0, f, f, f
	SetPlayerVirtualWorld 0, 0
	SetPlayerWantedLevel 0, 0
	SetPlayerWeather 0, 0
	SetPlayerWorldBounds 0, f, f, f, f
	SetSVarFloat "", f
	SetSVarInt "", 0
	SetSVarString "", ""
	SetSpawnInfo 0, 0, 0, f, f, f, f, 0, 0, 0, 0, 0, 0
	SetTimer "", 0, 0
	SetTimerEx "", 0, 0, ""
	SetVehicleAngularVelocity 0, f, f, f
	SetVehicleHealth 0, f
	SetVehicleNumberPlate 0, ""
	SetVehicleParamsCarDoors 0, 0, 0, 0, 0
	SetVehicleParamsEx 0, 0, 0, 0, 0, 0, 0, 0
	SetVehicleParamsForPlayer 0, 0, 0, 0
	SetVehiclePos 0, f, f, f
	SetVehicleToRespawn 0
	SetVehicleVelocity 0, f, f, f
	SetVehicleVirtualWorld 0, 0
	SetVehicleZAngle 0, f
	SetWeather 0
	SetWorldTime 0
	setproperty
	setarg 0, 0, 0
	ShowMenuForPlayer Menu:0, 0
	ShowNameTags 0
	ShowPlayerDialog 0, 0, 0, "", "", "", ""
	ShowPlayerMarkers 0
	ShowPlayerNameTagForPlayer 0, 0, 0
	SpawnPlayer 0
	StartRecordingPlayerData 0, 0, ""
	StopAudioStreamForPlayer 0
	StopObject 0
	StopPlayerObject 0, 0
	StopRecordingPlayerData 0
	strcat "", "", 0
	strcmp "", ""
	strdel "", 0, 0
	strfind "", ""
	strins "", "", 0
	strlen ""
	strmid "", "", 0, 0
	strpack "", ""
	strunpack "", ""
	strval ""
	TextDrawAlignment Text:0, 0
	TextDrawBackgroundColor Text:0, 0
	TextDrawBoxColor Text:0, 0
	TextDrawColor Text:0, 0
	TextDrawCreate f, f, ""
	TextDrawDestroy Text:0
	TextDrawFont Text:0, 0
	TextDrawHideForAll Text:0
	TextDrawHideForPlayer 0, Text:0
	TextDrawLetterSize Text:0, f, f
	TextDrawSetOutline Text:0, 0
	TextDrawSetPreviewModel Text:0, 0
	TextDrawSetPreviewRot Text:0, f, f, f, f
	TextDrawSetPreviewVehCol Text:0, 0, 0
	TextDrawSetProportional Text:0, 0
	TextDrawSetSelectable Text:0, 0
	TextDrawSetShadow Text:0, 0
	TextDrawSetString Text:0, ""
	TextDrawShowForAll Text:0
	TextDrawTextSize Text:0, f, f
	TextDrawUseBox Text:0, 0
	tickcount
	TogglePlayerClock 0, 0
	TogglePlayerControllable 0, 0
	TogglePlayerSpectating 0, 0
	tolower 0
	toupper 0
	UnBlockIpAddress ""
	Update3DTextLabelText Text3D:0, 0, ""
	UpdatePlayer3DTextLabelText 0, PlayerText3D:0, 0, ""
	UpdateVehicleDamageStatus 0, 0, 0, 0, 0
	UsePlayerPedAnims
	uudecode "", "", 0
	uuencode "", "", 0
	valstr "", 0
	VectorSize f, f, f

	max 0, 0
	min 0, 0
	swapchars 0

	listenport 0
	sendpacket "", 3, ""
	sendstring "", ""
}

