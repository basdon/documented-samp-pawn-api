/*  SA-MP Player Functions
 *
 *  (c) Copyright 2005-2015, SA-MP Team
 *
 */

#if defined _players_included
	#endinput
#endif
#define _players_included
#pragma library players

#define SPECIAL_ACTION_NONE				0
#define SPECIAL_ACTION_DUCK				1
#define SPECIAL_ACTION_USEJETPACK		2
#define SPECIAL_ACTION_ENTER_VEHICLE	3
#define SPECIAL_ACTION_EXIT_VEHICLE     4
#define SPECIAL_ACTION_DANCE1			5
#define SPECIAL_ACTION_DANCE2			6
#define SPECIAL_ACTION_DANCE3			7
#define SPECIAL_ACTION_DANCE4			8
#define SPECIAL_ACTION_HANDSUP			10
#define SPECIAL_ACTION_USECELLPHONE		11
#define SPECIAL_ACTION_SITTING			12
#define SPECIAL_ACTION_STOPUSECELLPHONE 13
#define SPECIAL_ACTION_DRINK_BEER		20
#define SPECIAL_ACTION_SMOKE_CIGGY		21
#define SPECIAL_ACTION_DRINK_WINE		22
#define SPECIAL_ACTION_DRINK_SPRUNK		23
#define SPECIAL_ACTION_CUFFED			24
#define SPECIAL_ACTION_CARRY			25

#define FIGHT_STYLE_NORMAL				4
#define FIGHT_STYLE_BOXING				5
#define FIGHT_STYLE_KUNGFU				6
#define FIGHT_STYLE_KNEEHEAD			7
#define FIGHT_STYLE_GRABKICK			15
#define FIGHT_STYLE_ELBOW				16

#define WEAPONSKILL_PISTOL 				0
#define WEAPONSKILL_PISTOL_SILENCED		1
#define WEAPONSKILL_DESERT_EAGLE		2
#define WEAPONSKILL_SHOTGUN				3
#define WEAPONSKILL_SAWNOFF_SHOTGUN		4
#define WEAPONSKILL_SPAS12_SHOTGUN		5
#define WEAPONSKILL_MICRO_UZI			6
#define WEAPONSKILL_MP5					7
#define WEAPONSKILL_AK47				8
#define WEAPONSKILL_M4					9
#define WEAPONSKILL_SNIPERRIFLE			10

#define WEAPONSTATE_UNKNOWN				-1
#define WEAPONSTATE_NO_BULLETS			0
#define WEAPONSTATE_LAST_BULLET			1
#define WEAPONSTATE_MORE_BULLETS		2
#define WEAPONSTATE_RELOADING			3

// Player
native SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
native SpawnPlayer(playerid);

// Player info
native SetPlayerPos(playerid, Float:x, Float:y, Float:z);
native SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z);
native GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z);
native SetPlayerFacingAngle(playerid,Float:ang);
native GetPlayerFacingAngle(playerid,&Float:ang);
native IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z);
native Float:GetPlayerDistanceFromPoint(playerid, Float:X, Float:Y, Float:Z);
native IsPlayerStreamedIn(playerid, forplayerid);
native SetPlayerInterior(playerid,interiorid);
native GetPlayerInterior(playerid);
native SetPlayerHealth(playerid, Float:health);
native GetPlayerHealth(playerid, &Float:health);
native SetPlayerArmour(playerid, Float:armour);
native GetPlayerArmour(playerid, &Float:armour);
native SetPlayerAmmo(playerid, weaponslot, ammo);
native GetPlayerAmmo(playerid);
native GetPlayerWeaponState(playerid);
native GetPlayerTargetPlayer(playerid);
native GetPlayerTargetActor(playerid);
native SetPlayerTeam(playerid, teamid);
native GetPlayerTeam(playerid);
native SetPlayerScore(playerid,score);
native GetPlayerScore(playerid);
native GetPlayerDrunkLevel(playerid);
native SetPlayerDrunkLevel(playerid, level);
native SetPlayerColor(playerid,color);
native GetPlayerColor(playerid);
native SetPlayerSkin(playerid, skinid);
native GetPlayerSkin(playerid);
native GivePlayerWeapon(playerid, weaponid, ammo);
native ResetPlayerWeapons(playerid);
native SetPlayerArmedWeapon(playerid, weaponid);
native GetPlayerWeaponData(playerid, slot, &weapons, &ammo);
native GivePlayerMoney(playerid,money);
native ResetPlayerMoney(playerid);
native SetPlayerName(playerid, const name[]);
native GetPlayerMoney(playerid);
native GetPlayerState(playerid);
native GetPlayerIp(playerid, name[], len);
native GetPlayerPing(playerid);
native GetPlayerWeapon(playerid);
native GetPlayerKeys(playerid, &keys, &updown, &leftright);
native GetPlayerName(playerid, const name[], len);
native SetPlayerTime(playerid, hour, minute);
native GetPlayerTime(playerid, &hour, &minute);
native TogglePlayerClock(playerid, toggle);
native SetPlayerWeather(playerid, weather);
native ForceClassSelection(playerid);
native SetPlayerWantedLevel(playerid, level);
native GetPlayerWantedLevel(playerid);
native SetPlayerFightingStyle(playerid, style);
native GetPlayerFightingStyle(playerid);
native SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z);
native GetPlayerVelocity( playerid, &Float:X, &Float:Y, &Float:Z );
native PlayCrimeReportForPlayer(playerid, suspectid, crime);
native PlayAudioStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0);
native StopAudioStreamForPlayer(playerid);
native SetPlayerShopName(playerid, shopname[]);
native SetPlayerSkillLevel(playerid, skill, level);
native GetPlayerSurfingVehicleID(playerid);
native GetPlayerSurfingObjectID(playerid);
native RemoveBuildingForPlayer(playerid, modelid, Float:fX, Float:fY, Float:fZ, Float:fRadius);
native GetPlayerLastShotVectors(playerid, &Float:fOriginX, &Float:fOriginY, &Float:fOriginZ, &Float:fHitPosX, &Float:fHitPosY, &Float:fHitPosZ);

// Attached to bone objects

#define MAX_PLAYER_ATTACHED_OBJECTS 10 // This is the number of attached indexes available ie 10 = 0-9

native SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0, materialcolor1 = 0, materialcolor2 = 0);
native RemovePlayerAttachedObject(playerid, index);
native IsPlayerAttachedObjectSlotUsed(playerid, index);
native EditAttachedObject(playerid, index);

// Per-player TextDraws

/// <summary>Creates a textdraw for a single player. This can be used as a way around the <a href="#TextDrawCreate">global</a> text-draw limit.</summary>
/// <param name="playerid">The ID of the player to create the textdraw for</param>
/// <param name="x">X-Coordinate</param>
/// <param name="y">Y-Coordinate</param>
/// <param name="text">The text in the textdraw</param>
/// <seealso name="PlayerTextDrawDestroy"/>
/// <seealso name="PlayerTextDrawColor"/>
/// <seealso name="PlayerTextDrawBoxColor"/>
/// <seealso name="PlayerTextDrawBackgroundColor"/>
/// <seealso name="PlayerTextDrawAlignment"/>
/// <seealso name="PlayerTextDrawFont"/>
/// <seealso name="PlayerTextDrawLetterSize"/>
/// <seealso name="PlayerTextDrawTextSize"/>
/// <seealso name="PlayerTextDrawSetOutline"/>
/// <seealso name="PlayerTextDrawSetShadow"/>
/// <seealso name="PlayerTextDrawSetProportional"/>
/// <seealso name="PlayerTextDrawUseBox"/>
/// <seealso name="PlayerTextDrawSetString"/>
/// <seealso name="PlayerTextDrawShow"/>
/// <seealso name="PlayerTextDrawHide"/>
/// <remarks>This feature (player-textdraws) was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   If you choose values for y that are less than 1, the first text row will be invisible and only the shadow is visible.<p/>
///   text[] must <b>NOT</b> be empty or the server will crash! If you need a textdraw that shows nothing, use " " (a space) or _ (underscore)<p/>
///   If the last character in the text is a space (" "), the text will all be blank.<p/>
///   If part of the text is off-screen, the color of the text will not show, only the shadow (if enabled) will. <p/>
/// </remarks>
/// <remarks>
///   This applies ONLY to sa-mp versions before 0.3z:<p/><p/>
///   Maximum length of textdraw is 800 characters. Longer text will crash the client in older versions.<p/>
///   If you use color codes (such as <b><c>~R~ ~G~</c></b>) beyond 255th character the client will crash trying to display the textdraw. <p/>
/// </remarks>
/// <remarks>Keyboard key mapping codes (such as <b><c>~k~~VEHICLE_ENTER_EXIT~</c></b> Doesn't work beyond 255th character. </remarks>
/// <remarks>
///   The x,y coordinate is the top left coordinate for the text draw area based on a 640x480 "canvas" (irrespective of screen resolution). If you plan on using <a href="#PlayerTextDrawAlignment">PlayerTextDrawAlignment</a> with alignment 3 (right), the x,y coordinate is the top right coordinate for the text draw.<p/>
///   This function merely CREATES the textdraw, you must use <a href="#PlayerTextDrawShow">PlayerTextDrawShow</a> to show it to a player.<p/>
///   It is recommended to use WHOLE numbers instead of decimal positions when creating player textdraws to ensure resolution friendly design. <p/>
/// </remarks>
/// <remarks>Player-textdraws are automatically destroyed when a player disconnects.</remarks>
/// <returns>The ID of the created textdraw.</returns>
native PlayerText:CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]);

native PlayerTextDrawDestroy(playerid, PlayerText:text);
native PlayerTextDrawLetterSize(playerid, PlayerText:text, Float:x, Float:y);
native PlayerTextDrawTextSize(playerid, PlayerText:text, Float:x, Float:y);
native PlayerTextDrawAlignment(playerid, PlayerText:text, alignment);
native PlayerTextDrawColor(playerid, PlayerText:text, color);
native PlayerTextDrawUseBox(playerid, PlayerText:text, use);
native PlayerTextDrawBoxColor(playerid, PlayerText:text, color);
native PlayerTextDrawSetShadow(playerid, PlayerText:text, size);
native PlayerTextDrawSetOutline(playerid, PlayerText:text, size);
native PlayerTextDrawBackgroundColor(playerid, PlayerText:text, color);
native PlayerTextDrawFont(playerid, PlayerText:text, font);
native PlayerTextDrawSetProportional(playerid, PlayerText:text, set);
native PlayerTextDrawSetSelectable(playerid, PlayerText:text, set);
native PlayerTextDrawShow(playerid, PlayerText:text);
native PlayerTextDrawHide(playerid, PlayerText:text);
native PlayerTextDrawSetString(playerid, PlayerText:text, string[]);
native PlayerTextDrawSetPreviewModel(playerid, PlayerText:text, modelindex);
native PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0);
native PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:text, color1, color2);

// Per-player variable system (PVars)
native SetPVarInt(playerid, varname[], int_value);
native GetPVarInt(playerid, varname[]);
native SetPVarString(playerid, varname[], string_value[]);
native GetPVarString(playerid, varname[], string_return[], len);
native SetPVarFloat(playerid, varname[], Float:float_value);
native Float:GetPVarFloat(playerid, varname[]);
native DeletePVar(playerid, varname[]);

// PVar enumeration
#define PLAYER_VARTYPE_NONE			0
#define PLAYER_VARTYPE_INT			1
#define PLAYER_VARTYPE_STRING		2
#define PLAYER_VARTYPE_FLOAT		3

native GetPVarsUpperIndex(playerid);
native GetPVarNameAtIndex(playerid, index, ret_varname[], ret_len);
native GetPVarType(playerid, varname[]);

#define MAX_CHATBUBBLE_LENGTH 144
native SetPlayerChatBubble(playerid, text[], color, Float:drawdistance, expiretime);

// Player control
native PutPlayerInVehicle(playerid, vehicleid, seatid);
native GetPlayerVehicleID(playerid);
native GetPlayerVehicleSeat(playerid);
native RemovePlayerFromVehicle(playerid);
native TogglePlayerControllable(playerid, toggle);
native PlayerPlaySound(playerid, soundid, Float:x, Float:y, Float:z);

/// <summary>Apply an animation to a player.</summary>
/// <param name="playerid">The ID of the player to apply the animation to</param>
/// <param name="animlib">The animation library from which to apply an animation</param>
/// <param name="animname">The name of the animation to apply, within the specified library</param>
/// <param name="fDelta">The speed to play the animation (use 4.1)</param>
/// <param name="loop">If set to <b><c>1</c></b>, the animation will loop. If set to <b><c>0</c></b>, the animation will play once</param>
/// <param name="lockx">If set to <b><c>0</c></b>, the player is returned to their old X coordinate once the animation is complete (for animations that move the player such as walking). <b><c>1</c></b> will not return them to their old position</param>
/// <param name="locky">Same as above but for the Y axis. Should be kept the same as the previous parameter</param>
/// <param name="freeze">Setting this to <b><c>1</c></b> will freeze the player at the end of the animation. <b><c>0</c></b> will not</param>
/// <param name="time">Timer in milliseconds. For a never-ending loop it should be <b><c>0</c></b></param>
/// <param name="forcesync">Set to <b><c>1</c></b> to make server sync the animation with all other players in streaming radius (optional). 2 works same as <b><c>1</c></b>, but will ONLY apply the animation to streamed-in players, but NOT the actual player being animated (useful for npc animations and persistent animations when players are being streamed)</param>
/// <seealso name="ClearAnimations"/>
/// <seealso name="SetPlayerSpecialAction"/>
/// <remarks>The 'forcesync' optional parameter, which defaults to 0, in most cases is not needed since players sync animations themselves. The 'forcesync' parameter can force all players who can see 'playerid' to play the animation regardless of whether the player is performing that animation. This is useful in circumstances where the player can't sync the animation themselves. For example, they may be paused.</remarks>
/// <remarks>An invalid animation library will crash the player's game.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the player specified does not exist, or any of the parameters are invalid (e.g. invalid library).</returns>
native ApplyAnimation(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0);

/// <summary>Clears all animations for the given player (it also cancels all current tasks such as jetpacking,parachuting,entering vehicles, driving (removes player out of vehicle), swimming, etc.. ).</summary>
/// <param name="playerid">The ID of the player to clear the animations of</param>
/// <param name="forcesync">Set to <b><c>1</c></b> to force playerid to sync the animation with other players in streaming radius (optional=0)</param>
/// <seealso name="ApplyAnimation"/>
/// <remarks>ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze parameter in <a href="#ApplyAnimation">ApplyAnimation</a>.</remarks>
/// <remarks>Unlike some other ways to remove player from a vehicle, this will also reset the vehicle's velocity to zero, instantly stopping the car. Player will appear on top of the vehicle with the same location as he was in his car seat.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even when the player specified is not connected.</returns>
native ClearAnimations(playerid, forcesync = 0);

native GetPlayerAnimationIndex(playerid); // return the index of any running applied animations (0 if none are running)
native GetAnimationName(index, animlib[], len1, animname[], len2); // get the animation lib/name for the index
native GetPlayerSpecialAction(playerid);
native SetPlayerSpecialAction(playerid,actionid);
native DisableRemoteVehicleCollisions(playerid, disable);

// Player world/map related
native SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size);
native DisablePlayerCheckpoint(playerid);
native SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size);
native DisablePlayerRaceCheckpoint(playerid);
native SetPlayerWorldBounds(playerid,Float:x_max,Float:x_min,Float:y_max,Float:y_min);
native SetPlayerMarkerForPlayer(playerid, showplayerid, color);
native ShowPlayerNameTagForPlayer(playerid, showplayerid, show);

#define MAPICON_LOCAL			  0 // displays in the player's local are
#define MAPICON_GLOBAL			  1 // displays always
#define MAPICON_LOCAL_CHECKPOINT  2 // displays in the player's local area and has a checkpoint marker
#define MAPICON_GLOBAL_CHECKPOINT 3 // displays always and has a checkpoint marker

native SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markertype, color, style = MAPICON_LOCAL);
native RemovePlayerMapIcon(playerid, iconid);

/// <summary>Enable/Disable the teleporting ability for a player by right-clicking on the map.</summary>
/// <param name="playerid">The ID of the player to allow teleport</param>
/// <param name="allow"><b><c>1</c></b> to allow, <b><c>0</c></b> to disallow</param>
/// <remarks><b>This function, as of 0.3d, is deprecated. Check <a href="#OnPlayerClickMap">OnPlayerClickMap</a>.</b></remarks>
/// <remarks>This function will work only if <a href="#AllowAdminTeleport">AllowAdminTeleport</a> is enabled, and you have to be an admin.</remarks>
/// <seealso name="AllowAdminTeleport"/>
native AllowPlayerTeleport(playerid, allow);

// Player camera
native SetPlayerCameraPos(playerid,Float:x, Float:y, Float:z);

#define CAMERA_CUT	2
#define CAMERA_MOVE 1

native SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, cut = CAMERA_CUT);
native SetCameraBehindPlayer(playerid);
native GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z);
native GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z);
native GetPlayerCameraMode(playerid);
native EnablePlayerCameraTarget(playerid, enable);
native GetPlayerCameraTargetObject(playerid);
native GetPlayerCameraTargetVehicle(playerid);
native GetPlayerCameraTargetPlayer(playerid);
native GetPlayerCameraTargetActor(playerid);
native Float:GetPlayerCameraAspectRatio(playerid);
native Float:GetPlayerCameraZoom(playerid);

/// <summary>You can use this function to attach the player camera to objects.</summary>
/// <param name="playerid">The ID of the player which will have your camera attached on object</param>
/// <param name="objectid">The object id which you want to attach the player camera</param>
/// <seealso name="AttachCameraToPlayerObject"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You need to create the object first, before attempting to attach a player camera for that.</remarks>
native AttachCameraToObject(playerid, objectid);

/// <summary>Attaches a player's camera to a player-object. The player is able to move their camera while it is attached to an object. Can be used with MovePlayerObject and AttachPlayerObjectToVehicle.</summary>
/// <param name="playerid">The ID of the player which will have their camera attached to a player-object</param>
/// <param name="playerobjectid">The ID of the player-object to which the player's camera will be attached</param>
/// <seealso name="AttachCameraToObject"/>
/// <seealso name="SetPlayerCameraPos"/>
/// <seealso name="SetPlayerCameraLookAt"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>The player-object must be created before attempting to attach the player's camera to it.</remarks>
native AttachCameraToPlayerObject(playerid, playerobjectid);

native InterpolateCameraPos(playerid, Float:FromX, Float:FromY, Float:FromZ, Float:ToX, Float:ToY, Float:ToZ, time, cut = CAMERA_CUT);
native InterpolateCameraLookAt(playerid, Float:FromX, Float:FromY, Float:FromZ, Float:ToX, Float:ToY, Float:ToZ, time, cut = CAMERA_CUT);

// Player conditionals
native IsPlayerConnected(playerid);
native IsPlayerInVehicle(playerid, vehicleid);
native IsPlayerInAnyVehicle(playerid);
native IsPlayerInCheckpoint(playerid);
native IsPlayerInRaceCheckpoint(playerid);

// Virtual Worlds
native SetPlayerVirtualWorld(playerid, worldid);
native GetPlayerVirtualWorld(playerid);

// Insane Stunts
native EnableStuntBonusForPlayer(playerid, enable);
native EnableStuntBonusForAll(enable);

// Spectating
#define SPECTATE_MODE_NORMAL	1
#define SPECTATE_MODE_FIXED		2
#define SPECTATE_MODE_SIDE		3

native TogglePlayerSpectating(playerid, toggle);
native PlayerSpectatePlayer(playerid, targetplayerid, mode = SPECTATE_MODE_NORMAL);
native PlayerSpectateVehicle(playerid, targetvehicleid, mode = SPECTATE_MODE_NORMAL);

// Recording for NPC playback
#define PLAYER_RECORDING_TYPE_NONE		0
#define PLAYER_RECORDING_TYPE_DRIVER	1
#define PLAYER_RECORDING_TYPE_ONFOOT	2

native StartRecordingPlayerData(playerid, recordtype, recordname[]);
native StopRecordingPlayerData(playerid);

native SelectTextDraw(playerid, hovercolor); // enables the mouse so the player can select a textdraw

/// <summary>Cancel textdraw selection with the mouse.</summary>
/// <param name="playerid">The ID of the player that should be the textdraw selection disabled</param>
/// <seealso name="SelectTextDraw"/>
/// <seealso name="TextDrawSetSelectable"/>
/// <seealso name="OnPlayerClickTextDraw"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>This function calls <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a> with <b><c>INVALID_TEXT_DRAW</c></b> (65535). Using this function inside OnPlayerClickTextDraw without catching this case will cause clients to go into an infinite loop.</remarks>
native CancelSelectTextDraw(playerid);	// cancel textdraw selection with the mouse

// Explosion

/// <summary>Creates an explosion that is only visible to a single player. This can be used to isolate explosions from other players or to make them only appear in specific <a href="http://wiki.sa-mp.com/wiki/SetPlayerVirtualWorld">virtual worlds</a>.</summary>
/// <param name="playerid">The ID of the player to create the explosion for</param>
/// <param name="X">The X coordinate of the explosion</param>
/// <param name="Y">The Y coordinate of the explosion</param>
/// <param name="Z">The Z coordinate of the explosion</param>
/// <param name="type">The explosion type</param>
/// <param name="Radius">The radius of the explosion</param>
/// <seealso name="CreateExplosion"/>
/// <remarks>This function was added in <b>SA-MP 0.3z R2-2</b> and will not work in earlier versions!</remarks>
/// <remarks>There is a limit as to how many explosions can be seen at once by a player. This is roughly 10.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the function failed to excute (player doesn't exist, invalid radius, or invalid explosion type).</returns>
native CreateExplosionForPlayer(playerid, Float:X, Float:Y, Float:Z, type, Float:Radius);

