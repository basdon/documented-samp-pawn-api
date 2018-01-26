/*  SA-MP Functions
 *
 *  (c) Copyright 2005-2015, SA-MP Team
 *
 */

#if defined _samp_included
	#endinput
#endif
#define _samp_included
#pragma library samp

#pragma tabsize 4
// Ignores warning 217 for properly indented PAWNO code
// It's tab size is 4 and often uses 4 spaces instead, PAWNCC's is 8

#include <core>
#include <float>
#include <string>
#include <file>
#include <time>
#include <datagram>
#include <a_players>
#include <a_vehicles>
#include <a_objects>
#include <a_actor>
#include <a_sampdb>

// Limits and internal constants
#define MAX_PLAYER_NAME							(24)
#define MAX_PLAYERS								(1000)
#define MAX_VEHICLES							(2000)
#define MAX_ACTORS								(1000)
#define INVALID_PLAYER_ID						(0xFFFF)
#define INVALID_VEHICLE_ID						(0xFFFF)
#define INVALID_ACTOR_ID						(0xFFFF)
#define NO_TEAM									(255)
#define MAX_OBJECTS								(1000)
#define INVALID_OBJECT_ID						(0xFFFF)
#define MAX_GANG_ZONES							(1024)
#define MAX_TEXT_DRAWS							(2048)
#define MAX_PLAYER_TEXT_DRAWS					(256)
#define MAX_MENUS								(128)
#define MAX_3DTEXT_GLOBAL						(1024)
#define MAX_3DTEXT_PLAYER						(1024)
#define MAX_PICKUPS								(4096)
#define INVALID_MENU							(0xFF)
#define INVALID_TEXT_DRAW						(0xFFFF)
#define INVALID_GANG_ZONE						(-1)
#define INVALID_3DTEXT_ID						(0xFFFF)

// --------------------------------------------------
// Natives
// --------------------------------------------------

// Util
native print(const string[]);
native printf(const format[], {Float,_}:...);
native format(output[], len, const format[], {Float,_}:...);
native SendClientMessage(playerid, color, const message[]);
native SendClientMessageToAll(color, const message[]);
native SendPlayerMessageToPlayer(playerid, senderid, const message[]);
native SendPlayerMessageToAll(senderid, const message[]);
native SendDeathMessage(killer, killee, weapon);
native SendDeathMessageToPlayer(playerid, killer, killee, weapon);
native GameTextForAll(const string[],time,style);
native GameTextForPlayer(playerid,const string[],time,style);
native SetTimer(funcname[], interval, repeating);
native SetTimerEx(funcname[], interval, repeating, const format[], {Float,_}:...);
native KillTimer(timerid);
native GetTickCount();
native GetMaxPlayers();
native CallRemoteFunction(const function[], const format[], {Float,_}:...);
native CallLocalFunction(const function[], const format[], {Float,_}:...);
native Float:VectorSize(Float:x, Float:y, Float:z);
native Float:asin(Float:value);
native Float:acos(Float:value);

/// <summary>Get the inversed value of an arc tangent in radians.</summary>
/// <param name="value">the input in arc tangents</param>
/// <seealso name="atan2"/>
/// <seealso name="floatsin"/>
/// <seealso name="floatcos"/>
/// <seealso name="floattan"/>
/// <returns>The radiant of the angle in radians.</returns>
native Float:atan(Float:value);

/// <summary>Get the multi-valued inversed value of an arc tangent in radians.</summary>
/// <param name="x">x size</param>
/// <param name="y">y size</param>
/// <seealso name="atan"/>
/// <seealso name="floatsin"/>
/// <seealso name="floatcos"/>
/// <seealso name="floattan"/>
/// <returns>The radiant of the angle in radians.</returns>
native Float:atan2(Float:x, Float:y);

native GetPlayerPoolSize();
native GetVehiclePoolSize();
native GetActorPoolSize();

// Hash
native SHA256_PassHash(password[], salt[], ret_hash[], ret_hash_len); // SHA256 for password hashing

// Server wide persistent variable system (SVars)
native SetSVarInt(varname[], int_value);
native GetSVarInt(varname[]);
native SetSVarString(varname[], string_value[]);
native GetSVarString(varname[], string_return[], len);
native SetSVarFloat(varname[], Float:float_value);
native Float:GetSVarFloat(varname[]);
native DeleteSVar(varname[]);

// SVar enumeration
#define	SERVER_VARTYPE_NONE			0
#define SERVER_VARTYPE_INT			1
#define SERVER_VARTYPE_STRING		2
#define SERVER_VARTYPE_FLOAT		3

native GetSVarsUpperIndex();
native GetSVarNameAtIndex(index, ret_varname[], ret_len);
native GetSVarType(varname[]);

// Game
native SetGameModeText(const string[]);

native SetTeamCount(count);

/// <summary>Adds a class to class selection. Classes are used so players may spawn with a skin of their choice.</summary>
/// <param name="modelid">The <a href="http://wiki.sa-mp.com/wiki/Skins">skin</a> which the player will spawn with</param>
/// <param name="spawn_x">The X coordinate of the spawnpoint of this class</param>
/// <param name="spawn_y">The Y coordinate of the spawnpoint of this class</param>
/// <param name="spawn_z">The Z coordinate of the spawnpoint of this class</param>
/// <param name="z_angle">The direction in which the player should face after spawning</param>
/// <param name="weapon1">The first spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="weapon1_ammo">The amount of ammunition for the primary spawn weapon</param>
/// <param name="weapon2">The second spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="weapon2_ammo">The amount of ammunition for the second spawn weapon</param>
/// <param name="weapon3">The third spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="weapon3_ammo">The amount of ammunition for the third spawn weapon</param>
/// <returns>
///   <ul>
///     <li>The <b>ID of the class</b> which was just added.</li>
///     <li><b>319</b> if the class limit (320) was reached. The highest possible class ID is 319.</li>
///   </ul>
/// </returns>
/// <remarks>
///    The maximum class ID is 319 (starting from 0, so a total of 320 classes).
///    When this limit is reached, any more classes that are added will replace ID 319.
/// </remarks>
/// <seealso name="AddPlayerClassEx"/>
/// <seealso name="SetSpawnInfo"/>
/// <seealso name="SetPlayerSkin"/>
native AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

/// <summary>This function is exactly the same as the <a href="#AddPlayerClass">AddPlayerClass</a> function, with the addition of a team parameter.</summary>
/// <param name="teamid">The team you want the player to spawn in</param>
/// <param name="modelid">The <a href="http://wiki.sa-mp.com/wiki/Skins">skin</a> which the player will spawn with</param>
/// <param name="spawn_x">The X coordinate of the class' spawn position</param>
/// <param name="spawn_y">The Y coordinate of the class' spawn position</param>
/// <param name="spawn_z">The Z coordinate of the class' spawn position</param>
/// <param name="z_angle">The direction in which the player will face after spawning</param>
/// <param name="weapon1">The first spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="weapon1_ammo">The amount of ammunition for the first spawn weapon</param>
/// <param name="weapon2">The second spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="weapon2_ammo">The amount of ammunition for the second spawn weapon</param>
/// <param name="weapon3">The third spawn-<a href="http://wiki.sa-mp.com/wiki/Weapons">weapon</a> for the player</param>
/// <param name="weapon3_ammo">The amount of ammunition for the third spawn weapon</param>
/// <returns>
///   <ul>
///     <li>The <b>ID of the class</b> which was just added.</li>
///     <li><b>319</b> if the class limit (320) was reached. The highest possible class ID is 319.</li>
///   </ul>
/// </returns>
/// <remarks>The maximum class ID is 319 (starting from 0, so a total of 320 classes). When this limit is reached, any more classes that are added will replace ID 319.</remarks>
/// <seealso name="AddPlayerClass"/>
/// <seealso name="SetSpawnInfo"/>
/// <seealso name="SetPlayerTeam"/>
/// <seealso name="SetPlayerSkin"/>
native AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

/// <summary>Adds a 'static' vehicle (models are pre-loaded for players) to the gamemode.</summary>
/// <param name="modelid">The <a href="http://wiki.sa-mp.com/wiki/Vehicle_Models">Model ID</a> for the vehicle</param>
/// <param name="spawn_x">The X-coordinate for the vehicle</param>
/// <param name="spawn_y">The Y-coordinate for the vehicle</param>
/// <param name="spawn_z">The Z-coordinate for the vehicle</param>
/// <param name="z_angle">Direction of vehicle - angle</param>
/// <param name="color1">The primary <a href="http://wiki.sa-mp.com/wiki/Color_ID">color ID</a>. -1 for random (random color chosen by client)</param>
/// <param name="color2">The secondary <a href="http://wiki.sa-mp.com/wiki/Color_ID">color ID</a>. -1 for random (random color chosen by client)</param>
/// <returns>
///   <ul>
///     <li>The vehicle ID of the vehicle created (between 1 and MAX_VEHICLES).</li>
///     <li><b>INVALID_VEHICLE_ID (65535)</b> if vehicle was not created (vehicle limit reached or invalid vehicle model ID passed).</li>
///   </ul>
/// </returns>
/// <remarks>Can only be used when the server first starts (under <a href="#OnGameModeInit">OnGameModeInit</a>).</remarks>
/// <seealso name="AddStaticVehicleEx"/>
/// <seealso name="CreateVehicle"/>
/// <seealso name="DestroyVehicle"/>
native AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);

/// <summary>Adds a 'static' vehicle (models are pre-loaded for players)to the gamemode. Differs from <a href="#AddStaticVehicle">AddStaticVehicle</a> in only one way: allows a respawn time to be set for when the vehicle is left unoccupied by the driver.</summary>
/// <param name="modelid">The <a href="http://wiki.sa-mp.com/wiki/Vehicle_Models">Model ID</a> for the vehicle</param>
/// <param name="spawn_x">The X-coordinate for the vehicle</param>
/// <param name="spawn_y">The Y-coordinate for the vehicle</param>
/// <param name="spawn_z">The Z-coordinate for the vehicle</param>
/// <param name="z_angle">The facing - angle for the vehicle</param>
/// <param name="color1">The primary <a href="http://wiki.sa-mp.com/wiki/Color_ID">color ID</a>. -1 for random (random color chosen by client)</param>
/// <param name="color2">The secondary <a href="http://wiki.sa-mp.com/wiki/Color_ID">color ID</a>. -1 for random (random color chosen by client)</param>
/// <param name="respawn_delay">The delay until the car is respawned without a driver, in seconds</param>
/// <param name="addsiren"><b>Added in 0.3.7; will not work in earlier versions.</b> <em>Has a default value 0.</em> Enables the vehicle to have a siren, providing the vehicle has a horn</param>
/// <returns>
///   <ul>
///     <li>The vehicle ID of the vehicle created (between 1 and MAX_VEHICLES).</li>
///     <li><b>INVALID_VEHICLE_ID (65535)</b> if vehicle was not created (vehicle limit reached or invalid vehicle model ID passed).</li>
///   </ul>
/// </returns>
/// <remarks>Can only be used when the server first starts (under <a href="#OnGameModeInit">OnGameModeInit</a>).</remarks>
/// <seealso name="AddStaticVehicle"/>
/// <seealso name="CreateVehicle"/>
/// <seealso name="DestroyVehicle"/>
native AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren=0);

/// <summary>This function adds a 'static' pickup to the game. These pickups support weapons, health, armor etc., with the ability to function without scripting them (weapons/health/armor will be given automatically).</summary>
/// <param name="model">The model of the pickup</param>
/// <param name="type">The pickup type. Determines how the pickup responds when picked up</param>
/// <param name="X">The X coordinate to create the pickup at</param>
/// <param name="Y">The Y coordinate to create the pickup at</param>
/// <param name="Z">The Z coordinate to create the pickup at</param>
/// <param name="virtualworld">The virtual world ID to put the pickup in. Use -1 to show the pickup in all worlds</param>
/// <returns>
///   <b><c>1</c></b> if the pickup is successfully created.
///   <p/>
///   <b><c>0</c></b> if failed to create.
/// </returns>
/// <remarks>This function doesn't return a pickup ID that you can use in, for example, OnPlayerPickUpPickup. Use CreatePickup if you'd like to assign IDs.</remarks>
/// <seealso name="CreatePickup"/>
/// <seealso name="DestroyPickup"/>
/// <seealso name="OnPlayerPickUpPickup"/>
native AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0);

native CreatePickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0);
native DestroyPickup(pickup);
native ShowNameTags(show);
native ShowPlayerMarkers(mode);
native GameModeExit();
native SetWorldTime(hour);
native GetWeaponName(weaponid, const weapon[], len);
native EnableTirePopping(enable); // deprecated function
native EnableVehicleFriendlyFire();

/// <summary>Toggle whether the usage of weapons in interiors is allowed or not.</summary>
/// <param name="allow">1 to enable weapons in interiors (enabled by default), 0 to disable weapons in interiors</param>
/// <remarks>This function does not work in the current SA:MP version!</remarks>
/// <seealso name="SetPlayerInterior"/>
/// <seealso name="GetPlayerInterior"/>
/// <seealso name="OnPlayerInteriorChange"/>
native AllowInteriorWeapons(allow);

native SetWeather(weatherid);
native SetGravity(Float:gravity);

/// <summary>This function will determine whether RCON admins will be teleported to their waypoint when they set one.</summary>
/// <param name="allow"><b><c>0</c></b> to disable and <b><c>1</c></b> to enable</param>
/// <remarks><b>This function, as of 0.3d, is deprecated. Please see <a href="#OnPlayerClickMap">OnPlayerClickMap</a>.</b></remarks>
/// <seealso name="IsPlayerAdmin"/>
/// <seealso name="AllowPlayerTeleport"/>
native AllowAdminTeleport(allow);

native SetDeathDropAmount(amount);
native CreateExplosion(Float:X, Float:Y, Float:Z, type, Float:Radius);
native EnableZoneNames(enable);
native UsePlayerPedAnims();		// Will cause the players to use CJ running/walking animations
native DisableInteriorEnterExits();  // will disable all interior enter/exits in the game.
native SetNameTagDrawDistance(Float:distance); // Distance at which nametags will start rendering on the client.
native DisableNameTagLOS(); // Disables the nametag Line-Of-Sight checking
native LimitGlobalChatRadius(Float:chat_radius);
native LimitPlayerMarkerRadius(Float:marker_radius);

// Npc
native ConnectNPC(name[], script[]);
native IsPlayerNPC(playerid);

// Admin
native IsPlayerAdmin(playerid);
native Kick(playerid);

/// <summary>Ban a player who is currently in the server. They will be unable to join the server ever again. The ban will be IP-based, and be saved in the samp.ban file in the server's root directory. <a href="#BanEx">BanEx</a> can be used to give a reason for the ban. IP bans can be added/removed using the RCON banip and unbanip commands (<a href="#SendRconCommand">SendRconCommand</a>).</summary>
/// <param name="playerid">The ID of the player to ban</param>
/// <seealso name="BanEx"/>
/// <seealso name="Kick"/>
/// <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Ban() (such as sending a message with SendClientMessage) will not reach the player. A timer must be used to delay the ban.</remarks>
/// <remarks></remarks>
native Ban(playerid);

/// <summary>Ban a player with a reason.</summary>
/// <param name="playerid">The ID of the player to ban</param>
/// <param name="reason">The reason for the ban</param>
/// <seealso name="Ban"/>
/// <seealso name="Kick"/>
/// <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Ban() (such as sending a message with SendClientMessage) will not reach the player. A timer must be used to delay the ban.</remarks>
native BanEx(playerid, const reason[]);

native SendRconCommand(command[]);
native GetPlayerNetworkStats(playerid, retstr[], retstr_size);
native GetNetworkStats(retstr[], retstr_size);
native GetPlayerVersion(playerid, const version[], len); // Returns the SA-MP client revision as reported by the player

/// <summary>Blocks an IP address from further communication with the server for a set amount of time (with wildcards allowed). Players trying to connect to the server with a blocked IP address will receive the generic "You are banned from this server." message. Players that are online on the specified IP before the block will timeout after a few seconds and, upon reconnect, will receive the same message.</summary>
/// <param name="ip_address">The IP to block</param>
/// <param name="timems">The time (in milliseconds) that the connection will be blocked for. <b><c>0</c></b> can be used for an indefinite block</param>
/// <seealso name="UnBlockIpAddress"/>
/// <seealso name="OnIncomingConnection"/>
/// <remarks>This function was added in <b>SA-MP 0.3z R2-2</b> and will not work in earlier versions!</remarks>
/// <remarks>Wildcards can be used with this function, for example blocking the IP <b><c>6.9.*.*</c></b> will block all IPs where the first two octets are <b><c>6</c></b> and <b><c>9</c></b> respectively. Any number can be in place of an asterisk.</remarks>
native BlockIpAddress(ip_address[], timems);

native UnBlockIpAddress(ip_address[]);

// Deprecated:
native GetServerVarAsString(const varname[], buffer[], len);
native GetServerVarAsInt(const varname[]);
native GetServerVarAsBool(const varname[]);
// These are the same 3 functions as above although they avoid the name ambiguity/conflict with the SVar system.
native GetConsoleVarAsString(const varname[], buffer[], len);
native GetConsoleVarAsInt(const varname[]);
native GetConsoleVarAsBool(const varname[]);

// Extended admin network stats
native GetServerTickRate();
native NetStats_GetConnectedTime(playerid);
native NetStats_MessagesReceived(playerid);
native NetStats_BytesReceived(playerid);
native NetStats_MessagesSent(playerid);
native NetStats_BytesSent(playerid);
native NetStats_MessagesRecvPerSecond(playerid);
native Float:NetStats_PacketLossPercent(playerid);
native NetStats_ConnectionStatus(playerid);
native NetStats_GetIpPort(playerid, ip_port[], ip_port_len);

// Menu
native Menu:CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0);
native DestroyMenu(Menu:menuid);
/// <summary>Adds an item to a specified menu.</summary>
/// <param name="menuid">The menu id to add an item to</param>
/// <param name="column">The column to add the item to</param>
/// <param name="title">The title for the new menu item</param>
/// <remarks>
///   <ul>
///     <li>Crashes when passed an invalid menu ID.</li>
///     <li>You can only have 12 items per menu (13th goes to the right side of the header of column name (colored), 14th and higher not display at all).</li>
///     <li>You can only use 2 columns (0 and 1).</li>
///     <li>You can only add 8 color codes per one item (~r~, ~g~ etc.).</li>
///     <li>Maximum length of menu item is 31 symbols. </li>
///   </ul>
/// </remarks>
/// <returns>The index of the row this item was added to.</returns>
/// <seealso name="CreateMenu"/>
/// <seealso name="SetMenuColumnHeader"/>
/// <seealso name="DestroyMenu"/>
/// <seealso name="OnPlayerSelectedMenuRow"/>
/// <seealso name="OnPlayerExitedMenu"/>
native AddMenuItem(Menu:menuid, column, const title[]);
native SetMenuColumnHeader(Menu:menuid, column, const columnheader[]);
native ShowMenuForPlayer(Menu:menuid, playerid);
native HideMenuForPlayer(Menu:menuid, playerid);
native IsValidMenu(Menu:menuid);
native DisableMenu(Menu:menuid);
native DisableMenuRow(Menu:menuid, row);
native Menu:GetPlayerMenu(playerid);

// Text Draw
#define TEXT_DRAW_FONT_SPRITE_DRAW	 4
#define TEXT_DRAW_FONT_MODEL_PREVIEW 5

native Text:TextDrawCreate(Float:x, Float:y, text[]);
native TextDrawDestroy(Text:text);
native TextDrawLetterSize(Text:text, Float:x, Float:y);
native TextDrawTextSize(Text:text, Float:x, Float:y);
native TextDrawAlignment(Text:text, alignment);
native TextDrawColor(Text:text, color);
native TextDrawUseBox(Text:text, use);
native TextDrawBoxColor(Text:text, color);
native TextDrawSetShadow(Text:text, size);
native TextDrawSetOutline(Text:text, size);
native TextDrawBackgroundColor(Text:text, color);
native TextDrawFont(Text:text, font);
native TextDrawSetProportional(Text:text, set);
native TextDrawSetSelectable(Text:text, set);
native TextDrawShowForPlayer(playerid, Text:text);
native TextDrawHideForPlayer(playerid, Text:text);
native TextDrawShowForAll(Text:text);
native TextDrawHideForAll(Text:text);
native TextDrawSetString(Text:text, string[]);
native TextDrawSetPreviewModel(Text:text, modelindex);
native TextDrawSetPreviewRot(Text:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0);
native TextDrawSetPreviewVehCol(Text:text, color1, color2);

// Gang Zones
native GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy);
native GangZoneDestroy(zone);
native GangZoneShowForPlayer(playerid, zone, color);
native GangZoneShowForAll(zone, color);
native GangZoneHideForPlayer(playerid, zone);
native GangZoneHideForAll(zone);
native GangZoneFlashForPlayer(playerid, zone, flashcolor);
native GangZoneFlashForAll(zone, flashcolor);
native GangZoneStopFlashForPlayer(playerid, zone);
native GangZoneStopFlashForAll(zone);

// Global 3D Text Labels
native Text3D:Create3DTextLabel(text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS=0);
native Delete3DTextLabel(Text3D:id);

/// <summary>Attach a 3D text label to a player.</summary>
/// <param name="id">The ID of the 3D text label to attach. Returned by <a href="#Create3DTextLabel">Create3DTextLabel</a></param>
/// <param name="playerid">The ID of the player to attach the label to</param>
/// <param name="OffsetX">The X offset from the player</param>
/// <param name="OffsetY">The Y offset from the player</param>
/// <param name="OffsetZ">The Z offset from the player</param>
/// <seealso name="Create3DTextLabel"/>
/// <seealso name="Delete3DTextLabel"/>
/// <seealso name="Attach3DTextLabelToVehicle"/>
/// <seealso name="Update3DTextLabelText"/>
/// <seealso name="CreatePlayer3DTextLabel"/>
/// <seealso name="DeletePlayer3DTextLabel"/>
/// <seealso name="UpdatePlayer3DTextLabelText"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>
/// <b><c>1</c></b>: The function executed successfully.<p/>
/// <b><c>0</c></b>: The function failed to execute. This means the player and/or label do not exist.
/// </returns>
native Attach3DTextLabelToPlayer(Text3D:id, playerid, Float:OffsetX, Float:OffsetY, Float:OffsetZ);

/// <summary>Attaches a 3D Text Label to a specific vehicle.</summary>
/// <param name="id">The ID of the 3D text label to attach. Returned by <a href="#Create3DTextLabel">Create3DTextLabel</a></param>
/// <param name="vehicleid">The vehicle you want to attach the 3D Text Label to</param>
/// <param name="OffsetX">The Offset-X coordinate of the player vehicle (the vehicle is 0.0,0.0,0.0).</param>
/// <param name="OffsetY">The Offset-Y coordinate of the player vehicle (the vehicle is 0.0,0.0,0.0).</param>
/// <param name="OffsetZ">The Offset-Z coordinate of the player vehicle (the vehicle is 0.0,0.0,0.0).</param>
/// <seealso name="Create3DTextLabel"/>
/// <seealso name="Delete3DTextLabel"/>
/// <seealso name="Attach3DTextLabelToPlayer"/>
/// <seealso name="Update3DTextLabelText"/>
/// <seealso name="CreatePlayer3DTextLabel"/>
/// <seealso name="DeletePlayer3DTextLabel"/>
/// <seealso name="UpdatePlayer3DTextLabelText"/>
/// <remarks>Attach3DTextLabelToPlayer was added in SA-MP 0.3a 	This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native Attach3DTextLabelToVehicle(Text3D:id, vehicleid, Float:OffsetX, Float:OffsetY, Float:OffsetZ);

native Update3DTextLabelText(Text3D:id, color, text[]);

// Per-player 3D Text Labels
native PlayerText3D:CreatePlayer3DTextLabel(playerid, text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, attachedplayer=INVALID_PLAYER_ID, attachedvehicle=INVALID_VEHICLE_ID, testLOS=0);
native DeletePlayer3DTextLabel(playerid, PlayerText3D:id);
native UpdatePlayer3DTextLabelText(playerid, PlayerText3D:id, color, text[]);

// Player GUI Dialog
#define DIALOG_STYLE_MSGBOX				0
#define DIALOG_STYLE_INPUT				1
#define DIALOG_STYLE_LIST				2
#define DIALOG_STYLE_PASSWORD			3
#define DIALOG_STYLE_TABLIST			4
#define DIALOG_STYLE_TABLIST_HEADERS	5

native ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[]);

// --------------------------------------------------
// Defines
// --------------------------------------------------

// States
#define PLAYER_STATE_NONE						(0)
#define PLAYER_STATE_ONFOOT						(1)
#define PLAYER_STATE_DRIVER						(2)
#define PLAYER_STATE_PASSENGER					(3)
#define PLAYER_STATE_EXIT_VEHICLE				(4) // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER		(5) // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER	(6) // (used internally)
#define PLAYER_STATE_WASTED						(7)
#define PLAYER_STATE_SPAWNED					(8)
#define PLAYER_STATE_SPECTATING					(9)

// Marker modes used by ShowPlayerMarkers()
#define PLAYER_MARKERS_MODE_OFF			(0)
#define PLAYER_MARKERS_MODE_GLOBAL		(1)
#define PLAYER_MARKERS_MODE_STREAMED	(2)

// Weapons
#define WEAPON_BRASSKNUCKLE				(1)
#define WEAPON_GOLFCLUB					(2)
#define WEAPON_NITESTICK				(3)
#define WEAPON_KNIFE					(4)
#define WEAPON_BAT						(5)
#define WEAPON_SHOVEL					(6)
#define WEAPON_POOLSTICK				(7)
#define WEAPON_KATANA					(8)
#define WEAPON_CHAINSAW					(9)
#define WEAPON_DILDO					(10)
#define WEAPON_DILDO2					(11)
#define WEAPON_VIBRATOR					(12)
#define WEAPON_VIBRATOR2				(13)
#define WEAPON_FLOWER					(14)
#define WEAPON_CANE						(15)
#define WEAPON_GRENADE					(16)
#define WEAPON_TEARGAS					(17)
#define WEAPON_MOLTOV					(18)
#define WEAPON_COLT45					(22)
#define WEAPON_SILENCED					(23)
#define WEAPON_DEAGLE					(24)
#define WEAPON_SHOTGUN					(25)
#define WEAPON_SAWEDOFF					(26)
#define WEAPON_SHOTGSPA					(27)
#define WEAPON_UZI						(28)
#define WEAPON_MP5						(29)
#define WEAPON_AK47						(30)
#define WEAPON_M4						(31)
#define WEAPON_TEC9						(32)
#define WEAPON_RIFLE					(33)
#define WEAPON_SNIPER					(34)
#define WEAPON_ROCKETLAUNCHER			(35)
#define WEAPON_HEATSEEKER				(36)
#define WEAPON_FLAMETHROWER				(37)
#define WEAPON_MINIGUN					(38)
#define WEAPON_SATCHEL					(39)
#define WEAPON_BOMB						(40)
#define WEAPON_SPRAYCAN					(41)
#define WEAPON_FIREEXTINGUISHER			(42)
#define WEAPON_CAMERA					(43)
#define WEAPON_PARACHUTE				(46)
#define WEAPON_VEHICLE					(49)
#define WEAPON_DROWN					(53)
#define WEAPON_COLLISION				(54)

// Keys
#define KEY_ACTION				(1)
#define KEY_CROUCH				(2)
#define KEY_FIRE				(4)
#define KEY_SPRINT				(8)
#define KEY_SECONDARY_ATTACK	(16)
#define KEY_JUMP				(32)
#define KEY_LOOK_RIGHT			(64)
#define KEY_HANDBRAKE			(128)
#define KEY_LOOK_LEFT			(256)
#define KEY_SUBMISSION			(512)
#define KEY_LOOK_BEHIND			(512)
#define KEY_WALK				(1024)
#define KEY_ANALOG_UP			(2048)
#define KEY_ANALOG_DOWN			(4096)
#define KEY_ANALOG_LEFT			(8192)
#define KEY_ANALOG_RIGHT		(16384)
#define KEY_YES					(65536)
#define KEY_NO					(131072)
#define KEY_CTRL_BACK			(262144)

#define KEY_UP					(-128)
#define KEY_DOWN				(128)
#define KEY_LEFT				(-128)
#define KEY_RIGHT				(128)

// --------------------------------------------------
// Forwards (Callback declarations)
// --------------------------------------------------

forward OnGameModeInit();
forward OnGameModeExit();
forward OnFilterScriptInit();
forward OnFilterScriptExit();
forward OnPlayerConnect(playerid);
forward OnPlayerDisconnect(playerid, reason);
forward OnPlayerSpawn(playerid);
forward OnPlayerDeath(playerid, killerid, reason);
forward OnVehicleSpawn(vehicleid);
forward OnVehicleDeath(vehicleid, killerid);
forward OnPlayerText(playerid, text[]);
forward OnPlayerCommandText(playerid, cmdtext[]);
forward OnPlayerRequestClass(playerid, classid);
forward OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
forward OnPlayerExitVehicle(playerid, vehicleid);
forward OnPlayerStateChange(playerid, newstate, oldstate);
forward OnPlayerEnterCheckpoint(playerid);
forward OnPlayerLeaveCheckpoint(playerid);
forward OnPlayerEnterRaceCheckpoint(playerid);
forward OnPlayerLeaveRaceCheckpoint(playerid);
forward OnRconCommand(cmd[]);
forward OnPlayerRequestSpawn(playerid);
forward OnObjectMoved(objectid);
forward OnPlayerObjectMoved(playerid, objectid);
forward OnPlayerPickUpPickup(playerid, pickupid);
forward OnVehicleMod(playerid, vehicleid, componentid);
forward OnEnterExitModShop(playerid, enterexit, interiorid);
forward OnVehiclePaintjob(playerid, vehicleid, paintjobid);
forward OnVehicleRespray(playerid, vehicleid, color1, color2);
forward OnVehicleDamageStatusUpdate(vehicleid, playerid);
forward OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
forward OnPlayerSelectedMenuRow(playerid, row);
forward OnPlayerExitedMenu(playerid);
forward OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
forward OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
forward OnRconLoginAttempt( ip[], password[], success );
forward OnPlayerUpdate(playerid);
forward OnPlayerStreamIn(playerid, forplayerid);
forward OnPlayerStreamOut(playerid, forplayerid);
forward OnVehicleStreamIn(vehicleid, forplayerid);
forward OnVehicleStreamOut(vehicleid, forplayerid);
forward OnActorStreamIn(actorid, forplayerid);
forward OnActorStreamOut(actorid, forplayerid);
forward OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
forward OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);
forward OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);
forward OnPlayerGiveDamageActor(playerid, damaged_actorid, Float:amount, weaponid, bodypart);
forward OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);
forward OnPlayerClickTextDraw(playerid, Text:clickedid);
forward OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
forward OnIncomingConnection(playerid, ip_address[], port);
forward OnTrailerUpdate(playerid, vehicleid);
forward OnVehicleSirenStateChange(playerid, vehicleid, newstate);

#define CLICK_SOURCE_SCOREBOARD		0
forward OnPlayerClickPlayer(playerid, clickedplayerid, source);

#define EDIT_RESPONSE_CANCEL		0
#define EDIT_RESPONSE_FINAL			1
#define EDIT_RESPONSE_UPDATE		2

forward OnPlayerEditObject( playerid, playerobject, objectid, response, 
Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ );

forward OnPlayerEditAttachedObject( playerid, response, index, modelid, boneid,
Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ,
Float:fRotX, Float:fRotY, Float:fRotZ,
Float:fScaleX, Float:fScaleY, Float:fScaleZ );

#define SELECT_OBJECT_GLOBAL_OBJECT	1
#define SELECT_OBJECT_PLAYER_OBJECT 2

forward OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ);

#define BULLET_HIT_TYPE_NONE			0
#define BULLET_HIT_TYPE_PLAYER			1
#define BULLET_HIT_TYPE_VEHICLE			2
#define BULLET_HIT_TYPE_OBJECT			3
#define BULLET_HIT_TYPE_PLAYER_OBJECT	4

forward OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);

// --------------------------------------------------
