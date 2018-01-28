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

/// <summary>Get the position of a player, represented by X, Y and Z coordinates.</summary>
/// <param name="playerid">The ID of the player to get the position of</param>
/// <param name="x">A float variable in which to store the X coordinate in, passed by reference</param>
/// <param name="y">A float variable in which to store the Y coordinate in, passed by reference</param>
/// <param name="z">A float variable in which to store the Z coordinate in, passed by reference</param>
/// <seealso name="SetPlayerPos"/>
/// <seealso name="GetVehiclePos"/>
/// <seealso name="IsPlayerInRangeOfPoint"/>
/// <seealso name="GetPlayerDistanceFromPoint"/>
/// <remarks>This function is known to return unreliable values when used in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a> and <a href="#OnPlayerRequestClass">OnPlayerRequestClass</a>. This is because the player is not spawned.</remarks>
/// <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure (i.e. player not connected).</returns>
native GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z);
native SetPlayerFacingAngle(playerid,Float:ang);

/// <summary>Gets the angle a player is facing.</summary>
/// <param name="playerid">The player you want to get the angle of</param>
/// <param name="Angle">The Float to store the angle in, passed by reference</param>
/// <seealso name="GetVehicleZAngle"/>
/// <seealso name="SetPlayerFacingAngle"/>
/// <remarks>Angles are reversed in GTA:SA; 90 degrees would be East in the real world, but in GTA:SA 90 degrees is in fact West. North and South are still 0/360 and 180. To convert this, simply do <b>360 - angle</b>.</remarks>
/// <remarks>Angles returned when inside a vehicle is rarely correct. To get the correct facing angle while inside a vehicle, use <a href="#GetVehicleZAngle">GetVehicleZAngle</a>.</remarks>
native GetPlayerFacingAngle(playerid,&Float:ang);
native IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z);

/// <summary>Calculate the distance between a player and a map coordinate.</summary>
/// <param name="playerid">The ID of the player to calculate the distance from</param>
/// <param name="X">The X map coordinate</param>
/// <param name="Y">The Y map coordinate</param>
/// <param name="Z">The Z map coordinate</param>
/// <seealso name="IsPlayerInRangeOfPoint"/>
/// <seealso name="GetVehicleDistanceFromPoint"/>
/// <seealso name="GetPlayerPos"/>
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>The distance between the player and the point as a float.</returns>
native Float:GetPlayerDistanceFromPoint(playerid, Float:X, Float:Y, Float:Z);
native IsPlayerStreamedIn(playerid, forplayerid);
native SetPlayerInterior(playerid,interiorid);
native GetPlayerInterior(playerid);

/// <summary>Retrieves the player's current interior. A list of currently known interiors with their positions can be found on <a href="http://wiki.sa-mp.com/wiki/InteriorIDs">this</a> page.</summary>
/// <param name="playerid">The player to get the interior ID of</param>
/// <seealso name="SetPlayerInterior"/>
/// <seealso name="GetPlayerVirtualWorld"/>
/// <remarks>Always returns 0 for NPCs.</remarks>
/// <returns>The interior ID the player is currently in.</returns>
native SetPlayerHealth(playerid, Float:health);

/// <summary>The function GetPlayerHealth allows you to retrieve the health of a player. Useful for cheat detection, among other things.</summary>
/// <param name="playerid">The ID of the player</param>
/// <param name="health">Float to store health, passed by reference</param>
/// <seealso name="SetPlayerHealth"/>
/// <seealso name="GetVehicleHealth"/>
/// <seealso name="GetPlayerArmour"/>
/// <remarks>
///   Even though the health can be set to near infinite values on the server side, the individual clients will only report values up to 255. Anything higher will wrap around; 256 becomes 0, 257 becomes 1, etc.<p/>
///   Health is obtained rounded to integers: set 50.15, but get 50.0 
/// </remarks>
/// <returns>
///   <b><c>1</c></b> - success.<p/>
///   <b><c>0</c></b> - failure (i.e. player not connected).<p/>
/// </returns>
native GetPlayerHealth(playerid, &Float:health);
native SetPlayerArmour(playerid, Float:armour);

/// <summary>This function stores the armour of a player into a variable.</summary>
/// <param name="playerid">The ID of the player that you want to get the armour of</param>
/// <param name="armour">The float to to store the armour in, passed by reference</param>
/// <seealso name="SetPlayerArmour"/>
/// <seealso name="GetPlayerHealth"/>
/// <seealso name="GetVehicleHealth"/>
/// <remarks>Even though the armour can be set to near infinite values on the server side, the individual clients will only report values up to 255. Anything higher will wrap around; 256 becomes 0, 257 becomes 1, etc. </remarks>
/// <remarks>Armour is obtained rounded to integers: set 50.15, but get 50.0 </remarks>
/// <returns>
///   <b><c>1</c></b> - success.<p/>
///   <b><c>0</c></b> - failure (i.e. player not connected).<p/>
/// </returns>
native GetPlayerArmour(playerid, &Float:armour);
native SetPlayerAmmo(playerid, weaponslot, ammo);

/// <summary>Gets the amount of ammo in a player's current weapon.</summary>
/// <param name="playerid">The ID of the player whose ammo to get</param>
/// <seealso name="SetPlayerAmmo"/>
/// <seealso name="GetPlayerWeaponData"/>
/// <remarks>The ammo can hold 16-bit values, therefore values over 32767 will return erroneous values.</remarks>
/// <returns>The amount of ammo in the player's current weapon.</returns>
native GetPlayerAmmo(playerid);

/// <summary>Check the state of a player's weapon.</summary>
/// <param name="playerid">The ID of the player to obtain the weapon state of</param>
/// <seealso name="GivePlayerWeapon"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Weapon states:</b><p/>
///   <ul>
///     <li><b><c>WEAPONSTATE_UNKNOWN</c></b> - unknown (Set when in a vehicle)</li>
///     <li><b><c>WEAPONSTATE_NO_BULLETS</c></b> - The weapon has no remaining ammo</li>
///     <li><b><c>WEAPONSTATE_LAST_BULLET</c></b> - the weapon has one remaining bullet</li>
///     <li><b><c>WEAPONSTATE_MORE_BULLETS</c></b> - the weapon has multiple bullets</li>
///     <li><b><c>WEAPONSTATE_RELOADING</c></b> - the player is reloading their weapon </li>
///   </ul>
/// </remarks>
/// <returns>The state of the player's weapon. <b><c>0</c></b> if player specified does not exist.</returns>
native GetPlayerWeaponState(playerid);

/// <summary>Check who a player is aiming at.</summary>
/// <param name="playerid">The ID of the player to get the target of</param>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <seealso name="OnPlayerGiveDamage"/>
/// <seealso name="OnPlayerTakeDamage"/>
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions! </remarks>
/// <remarks>Does not work for joypads/controllers, and after a certain distance. </remarks>
/// <remarks>Does not work for the sniper rifle, as it doesn't lock on to anything and as such can't and won't return a player. </remarks>
/// <returns>The ID of the target player, or <b><c>INVALID_PLAYER_ID</c></b> if none.</returns>
native GetPlayerTargetPlayer(playerid);

/// <summary>Gets id of an actor which is aimed by certain player.</summary>
/// <param name="playerid">The ID of the player to get the target of</param>
/// <seealso name="GetPlayerCameraTargetActor"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <seealso name="OnPlayerGiveDamageActor"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>Does not work for joypads/controllers, and after a certain distance. </remarks>
/// <remarks>Does not work for the sniper rifle, as it doesn't lock on to anything and as such can't and won't return a player. </remarks>
/// <returns>The ID of the targeted actor, or <b><c>INVALID_ACTOR_ID</c></b> if none.</returns>
native GetPlayerTargetActor(playerid);
native SetPlayerTeam(playerid, teamid);

/// <summary>Get the ID of the team the player is on.</summary>
/// <param name="playerid">The ID of the player to get the team of</param>
/// <seealso name="SetPlayerTeam"/>
/// <seealso name="SetTeamCount"/>
/// <returns>
///   <b><c>0-254</c></b>: The player's team. (<b><c>0</c></b> is a valid team).<p/>
///   <b><c>255</c></b>: Defined as <b><c>NO_TEAM</c></b>. The player is not on any team.<p/>
///   <b><c>-1</c></b>: The function failed to execute. Player is not connected.
/// </returns>
native GetPlayerTeam(playerid);
native SetPlayerScore(playerid,score);

/// <summary>This function returns a player's score as it was set using <a href="#SetPlayerScore">SetPlayerScore</a>.</summary>
/// <param name="playerid">The player to get the score of</param>
/// <seealso name="SetPlayerScore"/>
/// <seealso name="GetPlayerPing"/>
/// <returns>The player's score.</returns>
native GetPlayerScore(playerid);

/// <summary>Checks the player's level of drunkenness. If the level is less than 2000, the player is sober. The player's level of drunkness goes down slowly automatically (26 levels per second) but will always reach 2000 at the end (in 0.3b it will stop at zero). The higher drunkenness levels affect the player's camera, and the car driving handling. The level of drunkenness increases when the player drinks from a bottle (You can use <a href="#SetPlayerSpecialAction">SetPlayerSpecialAction</a> to give them bottles).</summary>
/// <param name="playerid">The player you want to check the drunkenness level of</param>
/// <seealso name="SetPlayerDrunkLevel"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>An integer with the level of drunkenness of the player.</returns>
native GetPlayerDrunkLevel(playerid);
native SetPlayerDrunkLevel(playerid, level);
native SetPlayerColor(playerid,color);

/// <summary>Gets the color of the player's name and radar marker. Only works after <a href="#SetPlayerColor">SetPlayerColor</a>.</summary>
/// <param name="playerid">The ID of the player to get the color of</param>
/// <seealso name="SetPlayerColor"/>
/// <seealso name="ChangeVehicleColor"/>
/// <remarks>GetPlayerColor will return <b><c>0</c></b> unless <a href="#SetPlayerColor">SetPlayerColor</a> has been used first.</remarks>
/// <returns>The player's color. <b><c>0</c></b> if no color set or player not connected.</returns>
native GetPlayerColor(playerid);
native SetPlayerSkin(playerid, skinid);

/// <summary>Returns the class of the players skin.</summary>
/// <param name="playerid">The player you want to get the skin from</param>
/// <seealso name="SetPlayerSkin"/>
/// <remarks>Returns the new skin after <a href="#SetSpawnInfo">SetSpawnInfo</a> is called but before the player actually respawns to get the new skin. </remarks>
/// <remarks>Returns the old skin if the player was spawned through <a href="#SpawnPlayer">SpawnPlayer</a> function. </remarks>
/// <returns>The skin id (<b><c>0</c></b> if invalid).</returns>
native GetPlayerSkin(playerid);

/// <summary>Give a player a weapon with a specified amount of ammo.</summary>
/// <param name="playerid">The ID of the player to give a weapon to</param>
/// <param name="weaponid">The ID of the weapon to give to the player</param>
/// <param name="ammo">The amount of ammo to give to the player</param>
/// <seealso name="SetPlayerArmedWeapon"/>
/// <seealso name="GetPlayerWeapon"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.<p/>
/// </returns>
native GivePlayerWeapon(playerid, weaponid, ammo);
native ResetPlayerWeapons(playerid);
native SetPlayerArmedWeapon(playerid, weaponid);

/// <summary>Get the weapon and ammo in a specific player's weapon slot (e.g. the weapon in the 'SMG' slot).</summary>
/// <param name="playerid">The ID of the player whose weapon data to retrieve</param>
/// <param name="slot">The weapon slot to get data for (<b><c>0-12</c></b>)</param>
/// <param name="weapons">A variable in which to store the weapon ID, passed by reference</param>
/// <param name="ammo">A variable in which to store the ammo, passed by reference</param>
/// <seealso name="GetPlayerWeapon"/>
/// <seealso name="GivePlayerWeapon"/>
/// <remarks>Old weapons with no ammo left are still returned.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player isn't connected and/or the weapon slot specified is invalid (valid is <b><c>0-12</c></b>).
/// </returns>
native GetPlayerWeaponData(playerid, slot, &weapons, &ammo);

/// <summary>Give money to or take money from a player.</summary>
/// <param name="playerid">The ID of the player to give money to or take money from</param>
/// <param name="money">The amount of money to give the player. Use a minus value to take money</param>
/// <seealso name="ResetPlayerMoney"/>
/// <seealso name="GetPlayerMoney"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native GivePlayerMoney(playerid,money);
native ResetPlayerMoney(playerid);
native SetPlayerName(playerid, const name[]);
native GetPlayerMoney(playerid);

/// <summary>Get a player's current state.</summary>
/// <param name="playerid">The ID of the player to get the current state of</param>
/// <seealso name="GetPlayerSpecialAction"/>
/// <seealso name="SetPlayerSpecialAction"/>
/// <seealso name="OnPlayerStateChange"/>
/// <remarks>
///   <b>States:</b><p/>
///   <ul>
///     <li><b><c>PLAYER_STATE_NONE</c></b> - empty (while initializing)</li>
///     <li><b><c>PLAYER_STATE_ONFOOT</c></b> - player is on foot</li>
///     <li><b><c>PLAYER_STATE_DRIVER</c></b> - player is the driver of a vehicle</li>
///     <li><b><c>PLAYER_STATE_PASSENGER</c></b> - player is passenger of a vehicle</li>
///     <li><b><c>PLAYER_STATE_WASTED</c></b> - player is dead or on class selection</li>
///     <li><b><c>PLAYER_STATE_SPAWNED</c></b> - player is spawned</li>
///     <li><b><c>PLAYER_STATE_SPECTATING</c></b> - player is spectating</li>
///     <li><b><c>PLAYER_STATE_EXIT_VEHICLE</c></b> - player exits a vehicle</li>
///     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_DRIVER</c></b> - player enters a vehicle as driver</li>
///     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_PASSENGER</c></b> - player enters a vehicle as passenger </li>
///   </ul>
/// </remarks>
/// <returns>The player's current state as an integer.</returns>
native GetPlayerState(playerid);

/// <summary>Get the specified player's IP address and store it in a string.</summary>
/// <param name="playerid">The ID of the player to get the IP address of</param>
/// <param name="ip">The string to store the player's IP address in, passed by reference</param>
/// <param name="len">The maximum length of the IP address (recommended 16)</param>
/// <seealso name="NetStats_GetIpPort"/>
/// <seealso name="GetPlayerName"/>
/// <seealso name="GetPlayerPing"/>
/// <seealso name="GetPlayerVersion"/>
/// <seealso name="OnIncomingConnection"/>
/// <seealso name="OnPlayerConnect"/>
/// <seealso name="OnPlayerDisconnect"/>
/// <remarks>This function does not work when used in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a> because the player is already disconnected. It will return an invalid IP (<b><c>255.255.255.255</c></b>). Save players' IPs under <a href="#OnPlayerConnect">OnPlayerConnect</a> if they need to be used under <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>. </remarks>
/// <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure.</returns>
native GetPlayerIp(playerid, name[], len);

/// <summary>Get the ping of a player. The ping measures the amount of time it takes for the server to 'ping' the client and for the client to send the message back.</summary>
/// <param name="playerid">The ID of the player to get the ping of</param>
/// <seealso name="GetPlayerIp"/>
/// <seealso name="GetPlayerName"/>
/// <seealso name="GetPlayerVersion"/>
/// <remarks>Player's ping may be <b><c>65535</c></b> for a while after a player connects</remarks>
/// <returns>The current ping of the player (expressed in milliseconds).</returns>
native GetPlayerPing(playerid);

/// <summary>Returns the ID of the weapon a player is currently holding.</summary>
/// <param name="playerid">The ID of the player to get the currently held weapon of</param>
/// <seealso name="GetPlayerWeaponData"/>
/// <seealso name="GivePlayerWeapon"/>
/// <seealso name="ResetPlayerWeapons"/>
/// <remarks>Prior to version <b>0.3z R1-2</b>, when the player state is <b>PLAYER_STATE_PASSENGER</b> this function returns the weapon held by the player before they entered the vehicle. If a cheat is used to spawn a weapon inside a vehicle, this function will not report it.</remarks>
/// <returns>The ID of the player's current weapon. Returns <b><c>-1</c></b> if the player specified does not exist.</returns>
native GetPlayerWeapon(playerid);

/// <summary>Check which keys a player is pressing.</summary>
/// <param name="playerid">The ID of the player to get the keys of</param>
/// <param name="keys">Bitmask containing the player's key states. <a href="http://wiki.sa-mp.com/wiki/Keys">List of keys</a></param>
/// <param name="updown">Up/down state</param>
/// <param name="leftright">Left/right state</param>
/// <seealso name="OnPlayerKeyStateChange"/>
/// <remarks>Only the FUNCTION of keys can be detected; not actual keys. For example, it is not possible to detect if a player presses <b>SPACE</b>, but you can detect if they press <b>SPRINT</b> (which can be mapped (assigned/binded) to ANY key (but is space by default)). </remarks>
/// <remarks>As of update 0.3.7, the keys "A" and "D" are not recognized when in a vehicle. However, keys "W" and "S" can be detected with the "keys" parameter. </remarks>
/// <returns>The keys are stored in the specified variables.</returns>
native GetPlayerKeys(playerid, &keys, &updown, &leftright);
native GetPlayerName(playerid, const name[], len);
native SetPlayerTime(playerid, hour, minute);

/// <summary>Get the player's current game time. Set by <a href="#SetWorldTime">SetWorldTime</a> or <a href="#SetPlayerTime">SetPlayerTime</a>, or by the game automatically if <a href="#TogglePlayerClock">TogglePlayerClock</a> is used.</summary>
/// <param name="playerid">The ID of the player to get the game time of</param>
/// <param name="hour">A variable in which to store the hour, passed by reference</param>
/// <param name="minute">A variable in which to store the minutes, passed by reference</param>
/// <seealso name="SetPlayerTime"/>
/// <seealso name="SetWorldTime"/>
/// <seealso name="TogglePlayerClock"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.<p/>
/// </returns>
native GetPlayerTime(playerid, &hour, &minute);
native TogglePlayerClock(playerid, toggle);
native SetPlayerWeather(playerid, weather);

/// <summary>Forces a player to go back to class selection.</summary>
/// <param name="playerid">The player to send back to class selection</param>
/// <seealso name="AddPlayerClass"/>
/// <seealso name="SetPlayerSkin"/>
/// <seealso name="GetPlayerSkin"/>
/// <seealso name="OnPlayerRequestClass"/>
/// <remarks>The player will not return to class selection until they re-spawn. This can be achieved with <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>, as seen in the below example.</remarks>
native ForceClassSelection(playerid);
native SetPlayerWantedLevel(playerid, level);

/// <summary>Gets the wanted level of a player.</summary>
/// <param name="playerid">The ID of the player that you want to get the wanted level of</param>
/// <seealso name="SetPlayerWantedLevel"/>
/// <seealso name="PlayCrimeReportForPlayer"/>
/// <returns>The player's wanted level.</returns>
native GetPlayerWantedLevel(playerid);
native SetPlayerFightingStyle(playerid, style);

/// <summary>Get the fighting style the player currently using.</summary>
/// <param name="playerid">The ID of the player to get the fighting style of</param>
/// <seealso name="SetPlayerFightingStyle"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Fighting styles:</b><p/>
///   <ul>
///     <li><b><c>FIGHT_STYLE_NORMAL</c></b></li>
///     <li><b><c>FIGHT_STYLE_BOXING</c></b></li>
///     <li><b><c>FIGHT_STYLE_KUNGFU</c></b></li>
///     <li><b><c>FIGHT_STYLE_KNEEHEAD</c></b></li>
///     <li><b><c>FIGHT_STYLE_GRABKICK</c></b></li>
///     <li><b><c>FIGHT_STYLE_ELBOW</c></b></li>
///   </ul>
/// </remarks>
/// <returns>The ID of the fighting style of the player.</returns>
native GetPlayerFightingStyle(playerid);
native SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z);

/// <summary>Get the velocity (speed) of a player on the X, Y and Z axes.</summary>
/// <param name="playerid">The player to get the speed from</param>
/// <param name="X">A float variable in which to store the velocity on the X axis, passed by reference</param>
/// <param name="Y">A float variable in which to store the velocity on the Y axis, passed by reference</param>
/// <param name="Z">A float variable in which to store the velocity on the Z axis, passed by reference</param>
/// <seealso name="SetPlayerVelocity"/>
/// <seealso name="SetVehicleVelocity"/>
/// <seealso name="GetVehicleVelocity"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
native GetPlayerVelocity( playerid, &Float:X, &Float:Y, &Float:Z );
native PlayCrimeReportForPlayer(playerid, suspectid, crime);
native PlayAudioStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0);
native StopAudioStreamForPlayer(playerid);
native SetPlayerShopName(playerid, shopname[]);
native SetPlayerSkillLevel(playerid, skill, level);

/// <summary>Get the ID of the vehicle that the player is surfing (stuck to the roof of).</summary>
/// <param name="playerid">The ID of the player you want to know the surfing vehicle ID of</param>
/// <seealso name="GetPlayerVehicleID"/>
/// <seealso name="GetPlayerVehicleSeat"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>The ID of the vehicle that the player is surfing. If they are not surfing a vehicle or the vehicle they are surfing has no driver, <b><c>INVALID_VEHICLE_ID</c></b>. If the player specified is not connected, <b><c>INVALID_VEHICLE_ID</c></b> also.</returns>
native GetPlayerSurfingVehicleID(playerid);

/// <summary>Returns the ID of the object the player is surfing on.</summary>
/// <param name="playerid">The ID of the player surfing the object</param>
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>The ID of the <b>moving</b> object the player is surfing. If the player isn't surfing a <b>moving</b> object, it will return <b><c>INVALID_OBJECT_ID</c></b>.</returns>
native GetPlayerSurfingObjectID(playerid);
native RemoveBuildingForPlayer(playerid, modelid, Float:fX, Float:fY, Float:fZ, Float:fRadius);

/// <summary>Retrieves the start and end (hit) position of the last bullet a player fired.</summary>
/// <param name="playerid">The ID of the player to get the last bullet shot information of</param>
/// <param name="fOriginX">A float variable in which to save the X coordinate of where the bullet originated from</param>
/// <param name="fOriginY">A float variable in which to save the Y coordinate of where the bullet originated from</param>
/// <param name="fOriginZ">A float variable in which to save the Z coordinate of where the bullet originated from</param>
/// <param name="fHitPosX">A float variable in which to save the X coordinate of where the bullet hit</param>
/// <param name="fHitPosY">A float variable in which to save the Y coordinate of where the bullet hit</param>
/// <param name="fHitPosZ">A float variable in which to save the Z coordinate of where the bullet hit</param>
/// <seealso name="GetPlayerWeaponData"/>
/// <seealso name="GetPlayerWeapon"/>
/// <seealso name="VectorSize"/>
/// <seealso name="OnPlayerWeaponShot"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>This function will only work when <a href="http://wiki.sa-mp.com/wiki/Lag_Compensation">lag compensation</a> is <b>enabled</b>. </remarks>
/// <remarks>If the player hit nothing, the hit positions will be <b><c>0</c></b>. This means you can't currently calculate how far a bullet travels through open air. </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.<p/>
/// </returns>
native GetPlayerLastShotVectors(playerid, &Float:fOriginX, &Float:fOriginY, &Float:fOriginZ, &Float:fHitPosX, &Float:fHitPosY, &Float:fHitPosZ);

// Attached to bone objects

#define MAX_PLAYER_ATTACHED_OBJECTS 10 // This is the number of attached indexes available ie 10 = 0-9

native SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0, materialcolor1 = 0, materialcolor2 = 0);
native RemovePlayerAttachedObject(playerid, index);
native IsPlayerAttachedObjectSlotUsed(playerid, index);

/// <summary>Enter edition mode for an attached object.</summary>
/// <param name="playerid">The ID of the player to enter in to edition mode</param>
/// <param name="index">The index (slot) of the attached object to edit</param>
/// <seealso name="SetPlayerAttachedObject"/>
/// <seealso name="RemovePlayerAttachedObject"/>
/// <seealso name="IsPlayerAttachedObjectSlotUsed"/>
/// <seealso name="EditObject"/>
/// <seealso name="EditPlayerObject"/>
/// <seealso name="SelectObject"/>
/// <seealso name="CancelEdit"/>
/// <seealso name="OnPlayerEditAttachedObject"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b> in vehicle) and moving your mouse.</remarks>
/// <remarks>
///   There are 7 clickable buttons in edition mode.<p/>
///   The three single icons that have X/Y/Z on them can be dragged to edit position/rotation/scale.<p/>
///   The four buttons in a row are to select the edition mode and save edition: [Move] [Rotate] [Scale] [Save].<p/>
///   Clicking save will call <a href="#OnPlayerEditAttachedObject">OnPlayerEditAttachedObject</a>. 
/// </remarks>
/// <remarks>Players will be able to scale objects up to a very large or negative value size. Limits should be put in place using <a href="#OnPlayerEditAttachedObject">OnPlayerEditAttachedObject</a> to abort the edit.</remarks>
/// <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure.</returns>
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

/// <summary>Gets an integer player variable's value.</summary>
/// <param name="playerid">The ID of the player whose player variable to get</param>
/// <param name="varname">The name of the player variable (case-insensitive). Assigned in SetPVarInt</param>
/// <seealso name="SetPVarInt"/>
/// <seealso name="SetPVarString"/>
/// <seealso name="GetPVarString"/>
/// <seealso name="SetPVarFloat"/>
/// <seealso name="GetPVarFloat"/>
/// <seealso name="DeletePVar"/>
/// <returns>The integer value of the specified player variable. It will still return 0 if the variable is not set, or the player does not exist.</returns>
native GetPVarInt(playerid, varname[]);
native SetPVarString(playerid, varname[], string_value[]);

/// <summary>Gets a player variable as a string.</summary>
/// <param name="playerid">The ID of the player whose player variable to get</param>
/// <param name="varname">The name of the player variable, set by <a href="#SetPVarString">SetPVarString</a></param>
/// <param name="string_return">The array in which to store the string value in, passed by reference</param>
/// <param name="len">The maximum length of the returned string</param>
/// <seealso name="SetPVarString"/>
/// <seealso name="SetPVarInt"/>
/// <seealso name="GetPVarInt"/>
/// <seealso name="SetPVarFloat"/>
/// <seealso name="GetPVarFloat"/>
/// <seealso name="DeletePVar"/>
/// <remarks>If length of string is zero (value not set), string_return text will not be updated or set to anything and will remain with old data, neccesying that you clear the variable to blank value if <a href="#GetPVarString">GetPVarString</a> returns <b><c>0</c></b> if that behavior is undesired </remarks>
/// <returns>The length of the string.</returns>
native GetPVarString(playerid, varname[], string_return[], len);
native SetPVarFloat(playerid, varname[], Float:float_value);

/// <summary>Gets a player variable as a float.</summary>
/// <param name="playerid">The ID of the player whose player variable you want to get</param>
/// <param name="varname">The name of the player variable</param>
/// <seealso name="SetPVarInt"/>
/// <seealso name="GetPVarInt"/>
/// <seealso name="SetPVarString"/>
/// <seealso name="GetPVarString"/>
/// <seealso name="SetPVarFloat"/>
/// <seealso name="DeletePVar"/>
/// <returns>
/// The float from the specified player variable.<p/>
/// forward LoadPos(playerid);.<p/>
/// public LoadPos(playerid).<p/>
/// {.<p/>
/// SetPlayerPos(playerid, GetPVarFloat(playerid,"xpos"), GetPVarFloat(playerid,"ypos"), GetPVarFloat(playerid,"zpos"));.<p/>
/// return 1;.<p/>
/// }.
/// </returns>
native Float:GetPVarFloat(playerid, varname[]);

/// <summary>Deletes a previously set player variable.</summary>
/// <param name="playerid">The ID of the player whose player variable to delete</param>
/// <param name="varname">The name of the player variable to delete</param>
/// <seealso name="SetPVarInt"/>
/// <seealso name="GetPVarInt"/>
/// <seealso name="SetPVarString"/>
/// <seealso name="GetPVarString"/>
/// <seealso name="SetPVarFloat"/>
/// <seealso name="GetPVarFloat"/>
/// <remarks>Once a variable is deleted, attempts to retrieve the value will return <b><c>0</c></b> (for integers and floats and <b><c>NULL</c></b> for strings.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. Either the player specified isn't connected or there is no variable set with the given name.
/// </returns>
native DeletePVar(playerid, varname[]);

// PVar enumeration
#define PLAYER_VARTYPE_NONE			0
#define PLAYER_VARTYPE_INT			1
#define PLAYER_VARTYPE_STRING		2
#define PLAYER_VARTYPE_FLOAT		3


/// <summary>Each PVar (player-variable) has its own unique identification number for lookup, this function returns the highest ID set for a player.</summary>
/// <param name="playerid">The ID of the player to get the upper PVar index of</param>
/// <seealso name="GetPVarNameAtIndex"/>
/// <seealso name="GetPVarType"/>
/// <returns>The highest set PVar ID.</returns>
native GetPVarsUpperIndex(playerid);

/// <summary>Retrieve the name of a player's pVar via the index.</summary>
/// <param name="playerid">The ID of the player whose player variable to get the name of</param>
/// <param name="index">The index of the player's pVar</param>
/// <param name="ret_varname">A string to store the pVar's name in, passed by reference</param>
/// <param name="ret_len">The max length of the returned string, use sizeof()</param>
/// <seealso name="GetPVarType"/>
/// <seealso name="GetPVarInt"/>
/// <seealso name="GetPVarFloat"/>
/// <seealso name="GetPVarString"/>
native GetPVarNameAtIndex(playerid, index, ret_varname[], ret_len);

/// <summary>Gets the type (integer, float or string) of a player variable.</summary>
/// <param name="playerid">The ID of the player whose player variable to get the type of</param>
/// <param name="varname">The name of the player variable to get the type of</param>
/// <seealso name="SetPVarInt"/>
/// <seealso name="GetPVarInt"/>
/// <seealso name="SetPVarString"/>
/// <seealso name="GetPVarString"/>
/// <seealso name="SetPVarFloat"/>
/// <seealso name="GetPVarFloat"/>
/// <seealso name="DeletePVar"/>
/// <remarks>
///   <b>Variable types:</b><p/>
///   <ul>
///     <li><b><c>PLAYER_VARTYPE_NONE</c></b> (pVar with name given does not exist)</li>
///     <li><b><c>PLAYER_VARTYPE_INT</c></b></li>
///     <li><b><c>PLAYER_VARTYPE_STRING</c></b></li>
///     <li><b><c>PLAYER_VARTYPE_FLOAT</c></b></li>
///   </ul>
/// </remarks>
/// <returns>Returns the type of the PVar. See table below.</returns>
native GetPVarType(playerid, varname[]);

#define MAX_CHATBUBBLE_LENGTH 144
native SetPlayerChatBubble(playerid, text[], color, Float:drawdistance, expiretime);

// Player control
native PutPlayerInVehicle(playerid, vehicleid, seatid);

/// <summary>This function gets the ID of the vehicle the player is currently in. Note: <b>NOT</b> the model id of the vehicle. See <a href="#GetVehicleModel">GetVehicleModel</a> for that.</summary>
/// <param name="playerid">The ID of the player in the vehicle that you want to get the ID of</param>
/// <seealso name="IsPlayerInVehicle"/>
/// <seealso name="IsPlayerInAnyVehicle"/>
/// <seealso name="GetPlayerVehicleSeat"/>
/// <seealso name="GetVehicleModel"/>
/// <returns>ID of the vehicle or <b><c>0</c></b> if not in a vehicle.</returns>
native GetPlayerVehicleID(playerid);

/// <summary>Find out which seat a player is in.</summary>
/// <param name="playerid">The ID of the player you want to get the seat of</param>
/// <seealso name="GetPlayerVehicleID"/>
/// <seealso name="PutPlayerInVehicle"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>Sometimes the result can be <b><c>128</c></b> which is an invalid seat ID. Circumstances of this are not yet known, but it is best to discard information when returned seat number is <b><c>128</c></b>.</remarks>
/// <returns>The ID of the seat the player is in. <b><c>-1</c></b> is not in vehicle, <b><c>0</c></b> is the driver, <b><c>1</c></b> is the front passenger, and <b><c>2</c></b> &amp; <b><c>3</c></b> are the rear passengers.</returns>
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
/// <param name="forcesync">Set to <b><c>1</c></b> to make server sync the animation with all other players in streaming radius. 2 works same as <b><c>1</c></b>, but will ONLY apply the animation to streamed-in players, but NOT the actual player being animated (useful for npc animations and persistent animations when players are being streamed) (optional=<b><c>0</c></b>)</param>
/// <seealso name="ClearAnimations"/>
/// <seealso name="SetPlayerSpecialAction"/>
/// <remarks>The 'forcesync' optional parameter, which defaults to 0, in most cases is not needed since players sync animations themselves. The 'forcesync' parameter can force all players who can see 'playerid' to play the animation regardless of whether the player is performing that animation. This is useful in circumstances where the player can't sync the animation themselves. For example, they may be paused.</remarks>
/// <remarks>An invalid animation library will crash the player's game.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the player specified does not exist, or any of the parameters are invalid (e.g. invalid library).</returns>
native ApplyAnimation(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time, forcesync = 0);

/// <summary>Clears all animations for the given player (it also cancels all current tasks such as jetpacking,parachuting,entering vehicles, driving (removes player out of vehicle), swimming, etc.. ).</summary>
/// <param name="playerid">The ID of the player to clear the animations of</param>
/// <param name="forcesync">Set to <b><c>1</c></b> to force playerid to sync the animation with other players in streaming radius (optional=<b><c>0</c></b>)</param>
/// <seealso name="ApplyAnimation"/>
/// <remarks>ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze parameter in <a href="#ApplyAnimation">ApplyAnimation</a>.</remarks>
/// <remarks>Unlike some other ways to remove player from a vehicle, this will also reset the vehicle's velocity to zero, instantly stopping the car. Player will appear on top of the vehicle with the same location as he was in his car seat.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even when the player specified is not connected.</returns>
native ClearAnimations(playerid, forcesync = 0);

/// <summary>Returns the index of any running applied animations.</summary>
/// <param name="playerid">ID of the player of whom you want to get the animation index of</param>
/// <seealso name="GetAnimationName"/>
/// <remarks>This function was added in <b>SA-MP 0.3b</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>0</c></b> if there is no animation applied.</returns>
native GetPlayerAnimationIndex(playerid); // return the index of any running applied animations (0 if none are running)

/// <summary>Get the animation library/name for the index.</summary>
/// <param name="index">The animation index, returned by <a href="#GetPlayerAnimationIndex">GetPlayerAnimationIndex</a></param>
/// <param name="animlib">String variable that stores the animation library</param>
/// <param name="len1">Size of the string that stores the animation library</param>
/// <param name="animname">String variable that stores the animation name</param>
/// <param name="len2">Size of the string that stores the animation name</param>
/// <seealso name="GetPlayerAnimationIndex"/>
/// <remarks>This function was added in <b>SA-MP 0.3b</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
native GetAnimationName(index, animlib[], len1, animname[], len2); // get the animation lib/name for the index

/// <summary>Retrieves a player's current <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a>.</summary>
/// <param name="playerid">The ID of the player to get the <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a> of</param>
/// <seealso name="SetPlayerSpecialAction"/>
/// <seealso name="GetPlayerState"/>
/// <returns>The <a href="http://wiki.sa-mp.com/wiki/SpecialActions">special action</a> of the player.</returns>
native GetPlayerSpecialAction(playerid);
native SetPlayerSpecialAction(playerid,actionid);

/// <summary>Disables collisions between occupied vehicles for a player.</summary>
/// <param name="playerid">The ID of the player for whom you want to disable collisions</param>
/// <param name="disable"><b><c>1</c></b> to disable collisions, <b><c>0</c></b> to enable collisions</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player specified does not exist.
/// </returns>
native DisableRemoteVehicleCollisions(playerid, disable);

// Player world/map related
native SetPlayerCheckpoint(playerid, Float:x, Float:y, Float:z, Float:size);

/// <summary>Disables (hides/destroys) a player's set checkpoint. Players can only have a single checkpoint set at a time. Checkpoints don't need to be disabled before setting another one.</summary>
/// <param name="playerid">The ID of the player whose checkpoint to disable</param>
/// <seealso name="SetPlayerCheckpoint"/>
/// <seealso name="IsPlayerInCheckpoint"/>
/// <seealso name="SetPlayerRaceCheckpoint"/>
/// <seealso name="DisablePlayerRaceCheckpoint"/>
/// <seealso name="IsPlayerInRaceCheckpoint"/>
/// <seealso name="OnPlayerEnterCheckpoint"/>
/// <seealso name="OnPlayerLeaveCheckpoint"/>
/// <seealso name="OnPlayerEnterRaceCheckpoint"/>
/// <seealso name="OnPlayerLeaveRaceCheckpoint"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is also returned if the player doesn't have a checkpoint shown already.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
/// </returns>
native DisablePlayerCheckpoint(playerid);
native SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size);

/// <summary>Disable any initialized race checkpoints for a specific player, since you can only have one at any given time.</summary>
/// <param name="playerid">The player to disable the current checkpoint for</param>
/// <seealso name="SetPlayerCheckpoint"/>
/// <seealso name="DisablePlayerCheckpoint"/>
/// <seealso name="IsPlayerInCheckpoint"/>
/// <seealso name="SetPlayerRaceCheckpoint"/>
/// <seealso name="IsPlayerInRaceCheckpoint"/>
/// <seealso name="OnPlayerEnterCheckpoint"/>
/// <seealso name="OnPlayerLeaveCheckpoint"/>
/// <seealso name="OnPlayerEnterRaceCheckpoint"/>
/// <seealso name="OnPlayerLeaveRaceCheckpoint"/>
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

/// <summary>Get the position of the player's camera.</summary>
/// <param name="playerid">The ID of the player to get the camera position of</param>
/// <param name="x">A float variable to store the X coordinate in, passed by reference</param>
/// <param name="y">A float variable to store the Y coordinate in, passed by reference</param>
/// <param name="z">A float variable to store the Z coordinate in, passed by reference</param>
/// <seealso name="SetPlayerCameraPos"/>
/// <seealso name="GetPlayerCameraZoom"/>
/// <seealso name="GetPlayerCameraAspectRatio"/>
/// <seealso name="GetPlayerCameraMode"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>Player's camera positions are only updated once a second, <b>unless aiming</b>.</remarks>
/// <remarks>It is recommended to set a 1 second timer if you wish to take action that relies on a player's camera position.</remarks>
native GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z);

/// <summary>This function will return the current direction of player's aiming in 3-D space, the coords are relative to the camera position, see <a href="#GetPlayerCameraPos">GetPlayerCameraPos</a>.</summary>
/// <param name="playerid">The ID of the player you want to obtain the camera front vector of</param>
/// <param name="x">A float to store the X coordinate, passed by reference</param>
/// <param name="y">A float to store the Y coordinate, passed by reference</param>
/// <param name="z">A float to store the Z coordinate, passed by reference</param>
/// <seealso name="GetPlayerCameraPos"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>In <b>0.3a</b> the camera front vector is only obtainable when player is inside a rhino, S.W.A.T tank, fire truck, or on foot. </remarks>
/// <remarks>Since <b>0.3b</b> the camera data can be obtained when the player is in any vehicle or on foot. </remarks>
/// <returns>The position is stored in the specified variables.</returns>
native GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z);

/// <summary>Returns the current GTA camera mode for the requested player. The camera modes are useful in determining whether a player is aiming, doing a passenger driveby etc.</summary>
/// <param name="playerid">The ID of the player whose camera mode to retrieve</param>
/// <seealso name="GetPlayerCameraPos"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <seealso name="SetPlayerCameraPos"/>
/// <seealso name="SetPlayerCameraLookAt"/>
/// <seealso name="SetCameraBehindPlayer"/>
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>The camera mode as an integer (or <b><c>-1</c></b> if player is not connected).</returns>
native GetPlayerCameraMode(playerid);

/// <summary>Toggle camera targeting functions for a player. Disabled by default to save bandwidth.</summary>
/// <param name="playerid">The ID of the player to toggle camera targeting functions for</param>
/// <param name="enable"><b><c>1</c></b> to enable camera targeting functions and <b><c>0</c></b> to disable them</param>
/// <seealso name="GetPlayerCameraTargetVehicle"/>
/// <seealso name="GetPlayerCameraTargetPlayer"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native EnablePlayerCameraTarget(playerid, enable);

/// <summary>Allows you to retrieve the ID of the object the player is looking at.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="GetPlayerCameraTargetVehicle"/>
/// <seealso name="GetPlayerCameraTargetPlayer"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <returns>The ID of the object playerid is looking at. If <b><c>INVALID_OBJECT_ID (65535)</c></b> is returned, playerid isn't looking at any object.</returns>
native GetPlayerCameraTargetObject(playerid);

/// <summary>Get the ID of the vehicle the player is looking at.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="GetPlayerCameraTargetPlayer"/>
/// <seealso name="GetPlayerCameraTargetObject"/>
/// <seealso name="EnablePlayerCameraTarget"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <remarks>This function can (obviously) only return one vehicle ID at a time, while the player may be looking at multiple. It generally seems to detect the closest vehicle first.</remarks>
/// <returns>The vehicle ID of the vehicle the player is looking at. <b><c>INVALID_VEHICLE_ID</c></b> if none.</returns>
native GetPlayerCameraTargetVehicle(playerid);

/// <summary>Allows you to retrieve the ID of the player the playerid is looking at.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="GetPlayerCameraTargetActor"/>
/// <seealso name="GetPlayerCameraTargetVehicle"/>
/// <seealso name="GetPlayerCameraTargetObject"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <remarks>Do not confuse this function with <a href="#GetPlayerTargetPlayer">GetPlayerTargetPlayer</a>. <a href="#GetPlayerTargetPlayer">GetPlayerTargetPlayer</a> returns the ID of the player playerid is aming at (with a weapon). <a href="#GetPlayerCameraTargetPlayer">GetPlayerCameraTargetPlayer</a> returns the ID of the player playerid is looking at (reference point is the <b>center of the screen</b>).</remarks>
/// <returns>The ID of the player the playerid is looking at.</returns>
native GetPlayerCameraTargetPlayer(playerid);

/// <summary>Allows you to retrieve the ID of the actor the player is looking at (if any).</summary>
/// <param name="playerid">The ID of the player to get the target actor of</param>
/// <seealso name="GetPlayerTargetActor"/>
/// <seealso name="GetPlayerCameraTargetPlayer"/>
/// <seealso name="GetPlayerCameraTargetVehicle"/>
/// <seealso name="GetPlayerCameraTargetObject"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>This function is disabled by default to save bandwidth. Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a> to enable it for each player.</remarks>
/// <remarks>This function only tells you which actor (if any) the player is <b>looking</b> at. To find out if they are <b>aiming</b> at them, you need to use <a href="#GetPlayerTargetActor">GetPlayerTargetActor</a>.</remarks>
/// <returns>The ID of the actor the player is looking at.</returns>
native GetPlayerCameraTargetActor(playerid);

/// <summary>Retrieves the aspect ratio of a player's camera.</summary>
/// <param name="playerid">The ID of the player to get the camera aspect ratio of</param>
/// <seealso name="GetPlayerCameraZoom"/>
/// <seealso name="GetPlayerCameraPos"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions! </remarks>
/// <remarks>The return value of this function represents the value of the "widescreen" option in the game's display settings, not the actual aspect ratio of the player's display.</remarks>
/// <returns>The aspect ratio of the player's camera, as a float. The aspect ratio can be one of three values: 4:3 (1.3333334, Float:0x3FAAAAAB) when widescreen is turned off, 5:4 (1.2470589, Float:0x3F9F9FA0) when letterbox mode is turned on, and 16:9 (1.7764707, Float:0x3FE36364) when widescreen is turned on regardless of the letterbox mode.</returns>
native Float:GetPlayerCameraAspectRatio(playerid);

/// <summary>Retrieves the game camera zoom level for a given player.</summary>
/// <param name="playerid">The ID of the player to get the camera zoom level of</param>
/// <seealso name="GetPlayerCameraAspectRatio"/>
/// <seealso name="GetPlayerCameraPos"/>
/// <seealso name="GetPlayerCameraFrontVector"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>This retrieves the zoom level of the GAME camera, not the camera WEAPON.</remarks>
/// <returns>The player's camera zoom level (camera, sniper etc.), a float.</returns>
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

/// <summary>Retrieves the current virtual world the player is in.</summary>
/// <param name="playerid">The ID of the player to get the virtual world of</param>
/// <seealso name="SetPlayerVirtualWorld"/>
/// <seealso name="GetVehicleVirtualWorld"/>
/// <seealso name="GetPlayerInterior"/>
/// <returns>The ID of the virtual world the player is currently in.</returns>
native GetPlayerVirtualWorld(playerid);

// Insane Stunts

/// <summary>Toggle stunt bonuses for a player. Enabled by default.</summary>
/// <param name="playerid">The ID of the player to toggle stunt bonuses for</param>
/// <param name="enable"><b><c>1</c></b> to enable stunt bonuses and <b><c>0</c></b> to disable them</param>
/// <seealso name="EnableStuntBonusForAll"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native EnableStuntBonusForPlayer(playerid, enable);

/// <summary>Enables or disables stunt bonuses for all players. If enabled, players will receive monetary rewards when performing a stunt in a vehicle (e.g. a wheelie).</summary>
/// <param name="enable"><b><c>1</c></b> to enable stunt bonuses or <b><c>0</c></b> to disable them</param>
/// <seealso name="EnableStuntBonusForPlayer"/>
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

