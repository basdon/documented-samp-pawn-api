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

/// <summary>Formats a string to include variables and other strings inside it.</summary>
/// <param name="output">The string to output the result to</param>
/// <param name="len">The maximum length output can contain</param>
/// <param name="format">The format string</param>
/// <param name="">Indefinite number of arguments of any tag</param>
/// <seealso name="print"/>
/// <seealso name="printf"/>
/// <remarks>This function doesn't support <a href="#strpack">packed strings</a>.</remarks>
/// <remarks>
///   <b>Format Specifiers:</b><p/>
///   <ul>
///     <li><b><c>%i</c></b> - integer (whole number)</li>
///     <li><b><c>%d</c></b> - integer (whole number).</li>
///     <li><b><c>%s</c></b> - string</li>
///     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
///     <li><b><c>%c</c></b> - ASCII character</li>
///     <li><b><c>%x</c></b> - hexadecimal number</li>
///     <li><b><c>%b</c></b> - binary number</li>
///     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
///     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
///   </ul>
/// </remarks>
/// <remarks>The values for the placeholders follow in the exact same order as parameters in the call. For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer variable, which is the person's age.</remarks>
/// <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder code. This number indicates the field width; if the size of the parameter to print at the position of the placeholder is smaller than the field width, the field is expanded with spaces. To cut the number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
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

/// <summary>Calls a public function in any script that is loaded.</summary>
/// <param name="function">Public function's name</param>
/// <param name="format">Tag/format of each variable</param>
/// <param name="">'Indefinite' number of arguments of any tag</param>
/// <seealso name="CallLocalFunction"/>
/// <returns>The value that the last public function returned.</returns>
/// <remarks>CallRemoteFunction crashes the server if it's passing an empty string.</remarks>
/// <remarks>
///   Format string placeholders:<p/>
///   <ul>
///     <li><b><c>c</c></b> - a single character</li>
///     <li><b><c>d</c></b> - an integer (whole) number</li>
///     <li><b><c>i</c></b> - an integer (whole) number</li>
///     <li><b><c>x</c></b> - a number in hexadecimal notation</li>
///     <li><b><c>f</c></b> - a floating point number</li>
///     <li><b><c>s</c></b> - a string</li>
///   </ul>
/// </remarks>
native CallRemoteFunction(const function[], const format[], {Float,_}:...);

/// <summary>Calls a public function from the script in which it is used.</summary>
/// <param name="function">Public function's name</param>
/// <param name="format">Tag/format of each variable</param>
/// <param name="">'Indefinite' number of arguments of any tag</param>
/// <seealso name="CallRemoteFunction"/>
/// <returns>The value that the <b>only</b> public function returned.</returns>
/// <remarks>CallLocalFunction crashes the server if it's passing an empty string.</remarks>
/// <remarks>
///   Format string placeholders:<p/>
///   <ul>
///     <li><b><c>c</c></b> - a single character</li>
///     <li><b><c>d</c></b> - an integer (whole) number</li>
///     <li><b><c>i</c></b> - an integer (whole) number</li>
///     <li><b><c>x</c></b> - a number in hexadecimal notation</li>
///     <li><b><c>f</c></b> - a floating point number</li>
///     <li><b><c>s</c></b> - a string</li>
///   </ul>
/// </remarks>
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

/// <summary>Deletes a previously set server variable.</summary>
/// <param name="varname">The name of the server variable to delete</param>
/// <seealso name="SetSVarInt"/>
/// <seealso name="GetSVarInt"/>
/// <seealso name="SetSVarString"/>
/// <seealso name="GetSVarString"/>
/// <seealso name="SetSVarFloat"/>
/// <seealso name="GetSVarFloat"/>
/// <remarks>Once a variable is deleted, attempts to retrieve the value will return <b><c>0</c></b> (for integers and floats and <b><c>NULL</c></b> for strings.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. There is no variable set with the given name.
/// </returns>
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

/// <summary>This function does exactly the same as AddStaticPickup, except it returns a pickup ID which can be used to destroy it afterwards and be tracked using <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</summary>
/// <param name="model">The <a href="http://wiki.sa-mp.com/wiki/Pickup_IDs">model</a> of the pickup</param>
/// <param name="type">The pickup spawn type (see table under remarks)</param>
/// <param name="X">The X coordinate to create the pickup at</param>
/// <param name="Y">The Y coordinate to create the pickup at</param>
/// <param name="Z">The Z coordinate to create the pickup at</param>
/// <param name="virtualworld">The virtual world ID of the pickup. Use <b><c>-1</c></b> to make the pickup show in all worlds (optional=<b><c>0</c></b>)</param>
/// <seealso name="AddStaticPickup"/>
/// <seealso name="DestroyPickup"/>
/// <seealso name="OnPlayerPickUpPickup"/>
/// <remarks>
///   <b>Known Bugs:</b><p/>
///   Pickups that have a X or Y lower than <b><c>-4096.0</c></b> or bigger than <b><c>4096.0</c></b> won't show up and won't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a> either.
/// </remarks>
/// <remarks>
///   The only type of pickup that can be picked up from inside a vehicle is <b><c>14</c></b> (except for special pickups such as bribes).<p/>
///   Pickups are shown to, and can be picked up by all players.<p/>
///   It is possible that if DestroyPickup() is used when a pickup is picked up, more than one player can pick up the pickup, due to lag. This can be circumvented through the use of variables.<p/>
///   Certain pickup types come with 'automatic responses', for example using an M4 model in the pickup will automatically give the player the weapon and some ammo. For fully scripted pickups, type 1 should be used. <p/>
/// </remarks>
/// <remarks>
///   <b>Available Pickup Types</b><p/>
///   Most other IDs are either undocumented or are similar to type <b><c>1</c></b> (but do not use them just because they seem similar to ID <b><c>1</c></b>, they might have side-effects like ID <b><c>18</c></b> and <b><c>20</c></b>).
///   <ul>
///     <li><b><c>0</c></b> - The pickup does not always display. If displayed, it can't be picked up and does not trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a> and it will stay after server shutdown.</li>
///     <li><b><c>1</c></b> - Exists always. Disables pickup scripts such as horseshoes and oysters to allow for scripted actions ONLY. Will trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a> every few seconds.</li>
///     <li><b><c>2</c></b> - Disappears after pickup, respawns after 30 seconds if the player is at a distance of at least 15 meters.</li>
///     <li><b><c>3</c></b> - Disappears after pickup, respawns after death.</li>
///     <li><b><c>4</c></b> - Disappears after 15 to 20 seconds. Respawns after death.</li>
///     <li><b><c>8</c></b> - Disappears after pickup, but has no effect.</li>
///     <li><b><c>11</c></b> - Blows up a few seconds after being created (bombs?)</li>
///     <li><b><c>12</c></b> - Blows up a few seconds after being created.</li>
///     <li><b><c>13</c></b> - Invisible. Triggers checkpoint sound when picked up with a vehicle, but doesn't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</li>
///     <li><b><c>14</c></b> - Disappears after pickup, can only be picked up with a vehicle. Triggers checkpoint sound.</li>
///     <li><b><c>15</c></b> - Same as type <b><c>2</c></b>.</li>
///     <li><b><c>18</c></b> - Similar to type <b><c>1</c></b>. Pressing Tab (<b><c>KEY_ACTION</c></b>) makes it disappear but the key press doesn't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</li>
///     <li><b><c>19</c></b> - Disappears after pickup, but doesn't respawn. Makes "cash pickup" sound if picked up.</li>
///     <li><b><c>20</c></b> - Similar to type <b><c>1</c></b>. Disappears when you take a picture of it with the Camera weapon, which triggers "Snapshot # out of 0" message. Taking a picture doesn't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</li>
///     <li><b><c>22</c></b> - Same as type <b><c>3</c></b>.</li>
///   </ul>
/// </remarks>
/// <returns>The ID of the created pickup, <b><c>-1</c></b> on failure (<a href="http://wiki.sa-mp.com/wiki/Limits">pickup max limit</a>).</returns>
native CreatePickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0);

/// <summary>Destroys a pickup created with <a href="#CreatePickup">CreatePickup</a>.</summary>
/// <param name="pickup">The ID of the pickup to destroy (returned by <a href="#CreatePickup">CreatePickup</a>)</param>
/// <seealso name="CreatePickup"/>
/// <seealso name="OnPlayerPickUpPickup"/>
native DestroyPickup(pickup);
native ShowNameTags(show);
native ShowPlayerMarkers(mode);
native GameModeExit();
native SetWorldTime(hour);
native GetWeaponName(weaponid, const weapon[], len);

/// <param name="show"><b><c>1</c></b> to enable, <b><c>0</c></b> to disable tire popping</param>
/// <remarks>This function was removed in <b>SA-MP 0.3</b>. Tire popping is enabled by default. If you want to disable tire popping, you'll have to manually script it using <a href="#OnVehicleDamageStatusUpdate">OnVehicleDamageStatusUpdate</a>.</remarks>
native EnableTirePopping(enable); // deprecated function

/// <summary>Enable friendly fire for team vehicles. Players will be unable to damage teammates' vehicles (<a href="#SetPlayerTeam">SetPlayerTeam</a> must be used!).</summary>
/// <seealso name="SetPlayerTeam"/>
/// <remarks>This function was added in <b>SA-MP 0.3x</b> and will not work in earlier versions!</remarks>
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

/// <summary>Create an explosion at the specified coordinates.</summary>
/// <param name="X">The X coordinate of the explosion</param>
/// <param name="Y">The Y coordinate of the explosion</param>
/// <param name="Z">The Z coordinate of the explosion</param>
/// <param name="type">The type of explosion</param>
/// <param name="radius">The explosion radius</param>
/// <seealso name="CreateExplosionForPlayer"/>
/// <remarks>There is a limit as to how many explosions can be seen at once by a player. This is roughly 10.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even when the explosion type and/or radius values are invalid.</returns>
native CreateExplosion(Float:X, Float:Y, Float:Z, type, Float:Radius);

/// <summary>This function allows to turn on zone / area names such as the "Vinewood" or "Doherty" text at the bottom-right of the screen as they enter the area. This is a gamemode option and should be set in the callback <a href="#OnGameModeInit">OnGameModeInit</a>.</summary>
/// <param name="enable">A toggle option for whether or not you'd like zone names on or off</param>
/// <remarks><b>This function was removed in SA-MP 0.3. This was due to crashes it caused.</b></remarks>
native EnableZoneNames(enable);
native UsePlayerPedAnims();		// Will cause the players to use CJ running/walking animations

/// <summary>Disable all the interior entrances and exits in the game (the yellow arrows at doors).</summary>
/// <seealso name="AllowInteriorWeapons"/>
/// <remarks>If the gamemode is changed after this function has been used, and the new gamemode doesn't disable markers, the markers will NOT reappear for already-connected players (but will for newly connected players).</remarks>
/// <remarks>This function will only work if it has been used BEFORE a player connects (it is recommended to use it in OnGameModeInit). It will not remove a connected player's markers.</remarks>
/// <returns>This function always returns <b><c>1</c></b>.</returns>
native DisableInteriorEnterExits();  // will disable all interior enter/exits in the game.
native SetNameTagDrawDistance(Float:distance); // Distance at which nametags will start rendering on the client.

/// <summary>Disables the nametag Line-Of-Sight checking so that players can see nametags through objects.</summary>
/// <seealso name="ShowNameTags"/>
/// <seealso name="ShowPlayerNameTagForPlayer"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>This can not be reversed until the server restarts.</remarks>
native DisableNameTagLOS(); // Disables the nametag Line-Of-Sight checking
native LimitGlobalChatRadius(Float:chat_radius);
native LimitPlayerMarkerRadius(Float:marker_radius);

// Npc

/// <summary>Connect an NPC to the server.</summary>
/// <param name="name">The name the NPC should connect as. Must follow the same rules as normal player names</param>
/// <param name="script">The NPC script name that is located in the <b>npcmodes</b> folder (without the .amx extension)</param>
/// <seealso name="IsPlayerNPC"/>
/// <seealso name="OnPlayerConnect"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>NPCs do not have nametags. These can be scripted with <a href="#Attach3DTextLabelToPlayer">Attach3DTextLabelToPlayer</a>.</remarks>
/// <returns>This function always return <b><c>1</c></b>.</returns>
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

/// <summary>Creates a menu.</summary>
/// <param name="title">The title for the new menu</param>
/// <param name="columns">How many colums shall the new menu have</param>
/// <param name="x">The X position of the menu (640x460 canvas - <b><c>0</c></b> would put the menu at the far left)</param>
/// <param name="y">The Y position of the menu (640x460 canvas - <b><c>0</c></b> would put the menu at the far top)</param>
/// <param name="col1width">The width for the first column</param>
/// <param name="col2width">The width for the second column (optional=<b><c>0.0</c></b>)</param>
/// <seealso name="AddMenuItem"/>
/// <seealso name="SetMenuColumnHeader"/>
/// <seealso name="DestroyMenu"/>
/// <seealso name="ShowMenuForPlayer"/>
/// <seealso name="HideMenuForPlayer"/>
/// <seealso name="OnPlayerSelectedMenuRow"/>
/// <seealso name="OnPlayerExitedMenu"/>
/// <remarks>
///   This function merely CREATES the menu - ShowMenuForPlayer must be used to show it.<p/>
///   You can only create and access 2 columns (0 &amp; 1).<p/>
///   If the title's length is equal to or greater than 32 chars the title is truncated to 30 characters. 
/// </remarks>
/// <remarks>There is a limit of 12 items per menu, and a limit of 128 menus in total.</remarks>
/// <returns>The ID of the new menu or -1 on failure.</returns>
native Menu:CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0);

/// <summary>Destroys the specified menu.</summary>
/// <param name="menuid">The menu ID to destroy</param>
/// <seealso name="CreateMenu"/>
/// <seealso name="SetMenuColumnHeader"/>
/// <seealso name="AddMenuItem"/>
/// <seealso name="OnPlayerSelectedMenuRow"/>
/// <seealso name="OnPlayerExitedMenu"/>
/// <returns><b><c>True</c></b> if the destroying was successful, otherwise <b><c>false</c></b>.</returns>
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

/// <summary>Disable a menu.</summary>
/// <param name="menuid">The ID of the menu to disable</param>
/// <seealso name="CreateMenu"/>
/// <seealso name="DestroyMenu"/>
/// <seealso name="AddMenuItem"/>
/// <remarks>Crashes when passed an invalid menu ID.</remarks>
native DisableMenu(Menu:menuid);

/// <summary>Disable a specific row in a menu <b>for all players</b>. It will be greyed-out and can't be selected by players.</summary>
/// <param name="menuid">The ID of the menu to disable a row of. Ensure this is valid, as an invalid menu ID will crash the entire server</param>
/// <param name="row">The ID of the row to disable (rows start at 0)</param>
/// <seealso name="CreateMenu"/>
/// <seealso name="DestroyMenu"/>
/// <seealso name="AddMenuItem"/>
/// <remarks>
///   Crashes when passed an invalid menu ID.<p/>
///   This function disabled the specified menu row for <b>all players</b>. There is no function to disable a menu row for a specific player. You'd have to create two menus - one with a row disabled, and one without. Or one per player. 
/// </remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the function fails. If an invalid row is specified, nothing will happen. If an invalid menu ID is specified, the server will crash.</returns>
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

/// <summary>Creates a 3D Text Label at a specific location in the world.</summary>
/// <param name="text">The initial text string</param>
/// <param name="color">The text Color, as an integer or hex in <b>RGBA</b> color format</param>
/// <param name="x">X-Coordinate</param>
/// <param name="y">Y-Coordinate</param>
/// <param name="z">Z-Coordinate</param>
/// <param name="DrawDistance">The distance from where you are able to see the 3D Text Label</param>
/// <param name="VirtualWorld">The virtual world in which you are able to see the 3D Text</param>
/// <param name="testLOS">Test the line-of-sight so this text can't be seen through objects (optional=<b><c>0</c></b>)</param>
/// <seealso name="Delete3DTextLabel"/>
/// <seealso name="Attach3DTextLabelToPlayer"/>
/// <seealso name="Attach3DTextLabelToVehicle"/>
/// <seealso name="Update3DTextLabelText"/>
/// <seealso name="CreatePlayer3DTextLabel"/>
/// <seealso name="DeletePlayer3DTextLabel"/>
/// <seealso name="UpdatePlayer3DTextLabelText"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   If <b><c>text[]</c></b> is empty, the server/clients next to the text might crash!<p/>
///   If the virtualworld is set as <b><c>-1</c></b> the text will not appear.
/// </remarks>
/// <remarks>drawdistance seems to be a lot smaller when spectating.</remarks>
/// <remarks>Use <a href="http://wiki.sa-mp.com/wiki/Colors_List#Inline_color_embedding">color embedding</a> for multiple colors in the text.</remarks>
/// <returns>The ID of the newly created 3D Text Label, or <b><c>INVALID_3DTEXT_ID</c></b> if the 3D Text Label limit (<b><c>MAX_3DTEXT_GLOBAL</c></b>) was reached.</returns>
native Text3D:Create3DTextLabel(text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS=0);

/// <summary>Delete a 3D text label (created with <a href="#Create3DTextLabel">Create3DTextLabel</a>).</summary>
/// <param name="id">The ID of the 3D text label to delete</param>
/// <seealso name="Create3DTextLabel"/>
/// <seealso name="Attach3DTextLabelToPlayer"/>
/// <seealso name="Attach3DTextLabelToVehicle"/>
/// <seealso name="Update3DTextLabelText"/>
/// <seealso name="CreatePlayer3DTextLabel"/>
/// <seealso name="DeletePlayer3DTextLabel"/>
/// <seealso name="UpdatePlayer3DTextLabelText"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the 3D text label was deleted, otherwise <b><c>0</c></b>.</returns>
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

/// <summary>Creates a 3D Text Label only for a specific player.</summary>
/// <param name="playerid">The player which should see the newly created 3DText Label</param>
/// <param name="text">The text to display</param>
/// <param name="color">The text color</param>
/// <param name="x">X Coordinate (or offset if attached)</param>
/// <param name="y">Y Coordinate (or offset if attached)</param>
/// <param name="z">Z Coordinate (or offset if attached)</param>
/// <param name="DrawDistance">The distance where you are able to see the 3D Text Label</param>
/// <param name="attachedplayer">The player you want to attach the 3D Text Label to. (optional=<b><c>INVALID_PLAYER_ID</c></b>)</param>
/// <param name="attachedvehicle">The vehicle you want to attach the 3D Text Label to. (optional=<b><c>INVALID_VEHICLE_ID</c></b>)</param>
/// <param name="testLOS">Test the line-of-sight so this text can't be seen through walls (optional=<b><c>0</c></b>)</param>
/// <seealso name="Create3DTextLabel"/>
/// <seealso name="Delete3DTextLabel"/>
/// <seealso name="Attach3DTextLabelToPlayer"/>
/// <seealso name="Attach3DTextLabelToVehicle"/>
/// <seealso name="Update3DTextLabelText"/>
/// <seealso name="DeletePlayer3DTextLabel"/>
/// <seealso name="UpdatePlayer3DTextLabelText"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>If <b><c>text[]</c></b> is empty, the server/clients next to the text might crash!</remarks>
/// <remarks>drawdistance seems to be a lot smaller when spectating.</remarks>
/// <returns>The ID of the newly created Player 3D Text Label, or <b><c>INVALID_3DTEXT_ID</c></b> if the Player 3D Text Label limit (<b><c>MAX_3DTEXT_PLAYER</c></b>) was reached.</returns>
native PlayerText3D:CreatePlayer3DTextLabel(playerid, text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, attachedplayer=INVALID_PLAYER_ID, attachedvehicle=INVALID_VEHICLE_ID, testLOS=0);

/// <summary>Destroy a 3D text label that was created using <a href="#CreatePlayer3DTextLabel">CreatePlayer3DTextLabel</a>.</summary>
/// <param name="playerid">The ID of the player whose 3D text label to delete</param>
/// <param name="id">The ID of the player's 3D text label to delete</param>
/// <seealso name="Create3DTextLabel"/>
/// <seealso name="Attach3DTextLabelToPlayer"/>
/// <seealso name="Attach3DTextLabelToVehicle"/>
/// <seealso name="Update3DTextLabelText"/>
/// <seealso name="CreatePlayer3DTextLabel"/>
/// <seealso name="UpdatePlayer3DTextLabelText"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the label specified doesn't exist.
/// </returns>
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
