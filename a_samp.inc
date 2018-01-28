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

/// <summary>Prints a string to the server console (not in-game chat) and logs (server_log.txt).</summary>
/// <param name="string">The string to print</param>
/// <seealso name="printf"/>
native print(const string[]);

/// <summary>Outputs a formatted string on the console (the server window, not the in-game chat).</summary>
/// <param name="format">The format string</param>
/// <param name="">Indefinite number of arguments of any tag</param>
/// <seealso name="print"/>
/// <seealso name="format"/>
/// <remarks>The format string or its output should not exceed 1024 characters. Anything beyond that length can lead to a server to crash.</remarks>
/// <remarks>This function doesn't support <a href="#strpack">packed</a> strings.</remarks>
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

/// <summary>This function sends a message to a specific player with a chosen color in the chat. The whole line in the chatbox will be in the set color unless color embedding is used (0.3c or later).</summary>
/// <param name="playerid">The ID of the player to display the message to</param>
/// <param name="color">The color of the message (RGBA)</param>
/// <param name="const message">The text that will be displayed <b>(max 144 characters)</b></param>
/// <seealso name="SendClientMessageToAll"/>
/// <seealso name="SendPlayerMessageToPlayer"/>
/// <seealso name="SendPlayerMessageToAll"/>
/// <remarks>If a message is longer than 144 characters, it will not be sent. Truncation can be used to prevent this. Displaying a message on multiple lines will also solve this issue. </remarks>
/// <remarks>Avoid using the percent sign (or format specifiers) in the actual message text without properly escaping it (like %%). It will result in crashes otherwise. </remarks>
/// <remarks>You can use color embedding for multiple colors in the message. </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is reported when the string is over 144 characters, but the message won't be sent.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native SendClientMessage(playerid, color, const message[]);

/// <summary>Displays a message in chat to all players. This is a multi-player equivalent of <a href="#SendClientMessage">SendClientMessage</a>.</summary>
/// <param name="color">The color of the message RGBA)</param>
/// <param name="const message">The message to show (max 144 characters)</param>
/// <seealso name="SendClientMessage"/>
/// <seealso name="SendPlayerMessageToAll"/>
/// <remarks>Avoid using format specifiers in your messages without formatting the string that is sent. It will result in crashes otherwise.</remarks>
/// <returns>This function always returns <b><c>1</c></b>.</returns>
native SendClientMessageToAll(color, const message[]);

/// <summary>Sends a message in the name of a player to another player on the server. The message will appear in the chat box but can only be seen by the user specified with 'playerid'. The line will start with the sender's name in their color, followed by the message in white.</summary>
/// <param name="playerid">The ID of the player who will receive the message</param>
/// <param name="senderid">The sender's ID. If invalid, the message will not be sent</param>
/// <param name="const message">The message that will be sent</param>
/// <seealso name="SendPlayerMessageToAll"/>
/// <seealso name="SendClientMessage"/>
/// <seealso name="SendClientMessageToAll"/>
/// <seealso name="OnPlayerText"/>
/// <remarks>Avoid using format specifiers in your messages without formatting the string that is sent. It will result in crashes otherwise.</remarks>
native SendPlayerMessageToPlayer(playerid, senderid, const message[]);

/// <summary>Sends a message in the name of a player to all other players on the server. The line will start with the sender's name in their color, followed by the message in white.</summary>
/// <param name="senderid">The ID of the sender. If invalid, the message will not be sent</param>
/// <param name="const message">The message that will be sent</param>
/// <seealso name="SendPlayerMessageToPlayer"/>
/// <seealso name="SendClientMessageToAll"/>
/// <seealso name="OnPlayerText"/>
/// <remarks>Avoid using format specifiers in your messages without formatting the string that is sent. It will result in crashes otherwise.</remarks>
native SendPlayerMessageToAll(senderid, const message[]);

/// <summary>Adds a death to the 'killfeed' on the right-hand side of the screen for all players.</summary>
/// <param name="killer">The ID of the killer (can be <b><c>INVALID_PLAYER_ID</c></b>)</param>
/// <param name="playerid">The ID of the player that died</param>
/// <param name="weapon">The <a href="http://wiki.sa-mp.com/wiki/Weapons">reason</a> (not always a weapon) for the victim's death. Special icons can also be used (<b><c>ICON_CONNECT</c></b> and <b><c>ICON_DISCONNECT</c></b>)</param>
/// <seealso name="SendDeathMessageToPlayer"/>
/// <seealso name="OnPlayerDeath"/>
/// <remarks>Death messages can be cleared by using a valid player ID for 'playerid' that is not connected.</remarks>
/// <remarks>To show a death message for just a single player, use <a href="#SendDeathMessageToPlayer">SendDeathMessageToPlayer</a>. </remarks>
/// <remarks>You can use NPCs to create your own custom death reasons. </remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the function fails to execute. The function fails to execute (no death message shown) if 'playerid' is invalid. If 'reason' is invalid, a generic skull-and-crossbones icon is shown. 'killerid' being invalid (<b><c>INVALID_PLAYER_ID</c></b>) is valid.</returns>
native SendDeathMessage(killer, killee, weapon);

/// <summary>Adds a death to the 'killfeed' on the right-hand side of the screen for a single player.</summary>
/// <param name="playerid">The ID of the player to send the death message to</param>
/// <param name="killer">The ID of the killer (can be <b><c>INVALID_PLAYER_ID</c></b>)</param>
/// <param name="killee">The ID of the player that died</param>
/// <param name="weapon">The <a href="http://wiki.sa-mp.com/wiki/Weapons">reason</a> (not always a weapon) for the victim's death. Special icons can also be used (<b><c>ICON_CONNECT</c></b> and <b><c>ICON_DISCONNECT</c></b>)</param>
/// <seealso name="SendDeathMessage"/>
/// <seealso name="OnPlayerDeath"/>
/// <remarks>This Function was added in <b>SA-MP 0.3z R2-2</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute.
/// </returns>
native SendDeathMessageToPlayer(playerid, killer, killee, weapon);

/// <summary>Shows 'game text' (on-screen text) for a certain length of time for all players.</summary>
/// <param name="const string">The text to be displayed</param>
/// <param name="time">The duration of the text being shown in milliseconds</param>
/// <param name="style">The style of text to be displayed</param>
/// <seealso name="GameTextForPlayer"/>
/// <seealso name="TextDrawShowForAll"/>
/// <returns>This function always returns <b><c>1</c></b>.</returns>
native GameTextForAll(const string[],time,style);

/// <summary>Shows 'game text' (on-screen text) for a certain length of time for a specific player.</summary>
/// <param name="playerid">The ID of the player to show the gametext for</param>
/// <param name="const string">The text to be displayed</param>
/// <param name="time">The duration of the text being shown in milliseconds</param>
/// <param name="style">The style of text to be displayed</param>
/// <seealso name="GameTextForAll"/>
/// <seealso name="TextDrawShowForPlayer"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is reported when the style and/or time is invalid. Nothing will happen though (no text displayed). May also cause game crashes.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means either the string is null or the player is not connected.
/// </returns>
native GameTextForPlayer(playerid,const string[],time,style);
native SetTimer(funcname[], interval, repeating);
native SetTimerEx(funcname[], interval, repeating, const format[], {Float,_}:...);

/// <summary>Kills (stops) a running timer.</summary>
/// <param name="timerid">The ID of the timer to kill (returned by <a href="#SetTimer">SetTimer</a> or <a href="#SetTimerEx">SetTimerEx</a>)</param>
/// <seealso name="SetTimer"/>
/// <seealso name="SetTimerEx"/>
/// <returns>This function always returns <b><c>0</c></b>.</returns>
native KillTimer(timerid);

/// <summary>Returns the uptime of the actual server (not the SA-MP server) in milliseconds.</summary>
/// <seealso name="tickcount"/>
/// <remarks>GetTickCount will cause problems on servers with uptime of over 24 days as GetTickCount will eventually warp past the integer size constraints. However using <a href="https://gist.github.com/ziggi/5d7d8dc42f54531feba7ae924c608e73">this</a> function fixes the problem.</remarks>
/// <remarks>One common use for GetTickCount is for benchmarking. It can be used to calculate how much time some code takes to execute.</remarks>
/// <returns>Uptime of the actual server (not the SA-MP server).</returns>
native GetTickCount();

/// <summary>Returns the maximum number of players that can join the server, as set by the server variable 'maxplayers' in server.cfg.</summary>
/// <seealso name="GetPlayerPoolSize"/>
/// <seealso name="IsPlayerConnected"/>
/// <remarks>This function can not be used in place of <b><c>MAX_PLAYERS</c></b>. It can not be used at compile time (e.g. for array sizes). <b><c>MAX_PLAYERS</c></b> should always be re-defined to what the 'maxplayers' var will be, or higher.</remarks>
/// <returns>The maximum number of players that can join the server.</returns>
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


/// <summary>Gets the highest playerid currently in use on the server.</summary>
/// <seealso name="GetVehiclePoolSize"/>
/// <seealso name="GetMaxPlayers"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>The highest playerid currently in use on the server or <b><c>0</c></b> if there are no connected players.</returns>
native GetPlayerPoolSize();

/// <summary>Gets the highest vehicleid currently in use on the server.</summary>
/// <seealso name="GetPlayerPoolSize"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>The highest vehicleid currently in use on the server or <b><c>0</c></b> if there are no created vehicles.</returns>
native GetVehiclePoolSize();

/// <summary>Gets the highest actorid created on the server.</summary>
/// <seealso name="CreateActor"/>
/// <seealso name="IsValidActor"/>
/// <seealso name="SetActorHealth"/>
/// <remarks>This function was added in <b><b>SA-MP 0.3.7</b></b> and will not work in earlier versions!</remarks>
/// <returns>The highest actorid created on the server or <b><c>0</c></b> if there are no created actors.</returns>
native GetActorPoolSize();

// Hash

/// <summary>Hashes a password using the SHA-256 hashing algorithm. Includes a salt. The output is always 256 bytes in length, or the equivalent of 64 Pawn cells.</summary>
/// <param name="password">The password to hash</param>
/// <param name="salt">The salt to use in the hash</param>
/// <param name="ret_hash">The returned hash</param>
/// <param name="ret_hash_len">The returned hash maximum length</param>
/// <remarks>This function was added in <b>SA-MP 0.3.7-R1</b> and will not work in earlier versions!</remarks>
/// <remarks>The salt is appended to the end of the password, meaning password 'foo' and salt 'bar' would form 'foobar'. </remarks>
/// <remarks>The salt should be random, unique for each player and at least as long as the hashed password. It is to be stored alongside the actual hash in the player's account. </remarks>
native SHA256_PassHash(password[], salt[], ret_hash[], ret_hash_len); // SHA256 for password hashing

// Server wide persistent variable system (SVars)
native SetSVarInt(varname[], int_value);

/// <summary>Gets an integer server variable's value.</summary>
/// <param name="varname">The name of the server variable (case-insensitive). Assigned in SetSVarInt</param>
/// <seealso name="SetSVarInt"/>
/// <seealso name="SetSVarString"/>
/// <seealso name="GetSVarString"/>
/// <seealso name="SetSVarFloat"/>
/// <seealso name="GetSVarFloat"/>
/// <seealso name="DeleteSVar"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7 R2</b> and will not work in earlier versions!</remarks>
/// <returns>The integer value of the specified server variable. It will still return <b><c>0</c></b> if the variable is not set.</returns>
native GetSVarInt(varname[]);
native SetSVarString(varname[], string_value[]);

/// <summary>Gets a string server variable's value.</summary>
/// <param name="varname">The name of the server variable (case-insensitive). Assigned in <a href="#SetSVarString">SetSVarString</a></param>
/// <param name="string_return">The array in which to store the string value in, passed by reference</param>
/// <param name="len">The maximum length of the returned string</param>
/// <seealso name="SetSVarInt"/>
/// <seealso name="GetSVarInt"/>
/// <seealso name="SetSVarString"/>
/// <seealso name="SetSVarFloat"/>
/// <seealso name="GetSVarFloat"/>
/// <seealso name="DeleteSVar"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7 R2</b> and will not work in earlier versions!</remarks>
/// <returns>The length of the string.</returns>
native GetSVarString(varname[], string_return[], len);
native SetSVarFloat(varname[], Float:float_value);

/// <summary>Gets a float server variable's value.</summary>
/// <param name="varname">The name of the server variable (case-insensitive). Assigned in <a href="#SetSVarFloat">SetSVarFloat</a></param>
/// <seealso name="SetSVarInt"/>
/// <seealso name="GetSVarInt"/>
/// <seealso name="SetSVarString"/>
/// <seealso name="GetSVarString"/>
/// <seealso name="SetSVarFloat"/>
/// <seealso name="DeleteSVar"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7 R2</b> and will not work in earlier versions!</remarks>
/// <returns>The float value of the specified server variable. It will still return <b><c>0</c></b> if the variable is not set.</returns>
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


/// <summary>Each SVar (server-variable) has its own unique identification number for lookup, this function returns the highest ID.</summary>
/// <seealso name="GetSVarNameAtIndex"/>
/// <seealso name="GetSVarType"/>
/// <returns>The highest set SVar ID.</returns>
native GetSVarsUpperIndex();

/// <summary>Retrieve the name of a sVar via the index.</summary>
/// <param name="index">The index of the sVar</param>
/// <param name="ret_varname">A string to store the sVar's name in, passed by reference</param>
/// <param name="ret_len">The max length of the returned string, use sizeof()</param>
/// <seealso name="GetSVarType"/>
/// <seealso name="GetSVarInt"/>
/// <seealso name="GetSVarFloat"/>
/// <seealso name="GetSVarString"/>
native GetSVarNameAtIndex(index, ret_varname[], ret_len);

/// <summary>Gets the type (integer, float or string) of a server variable.</summary>
/// <param name="varname">The name of the server variable to get the type of</param>
/// <seealso name="SetSVarInt"/>
/// <seealso name="GetSVarInt"/>
/// <seealso name="SetSVarString"/>
/// <seealso name="GetSVarString"/>
/// <seealso name="SetSVarFloat"/>
/// <seealso name="GetSVarFloat"/>
/// <seealso name="DeleteSVar"/>
/// <remarks>
///   <b>Variable types:</b><p/>
///   <ul>
///     <li><b><c>SERVER_VARTYPE_NONE</c></b> (sVar with name given does not exist)</li>
///     <li><b><c>SERVER_VARTYPE_INT</c></b></li>
///     <li><b><c>SERVER_VARTYPE_STRING</c></b></li>
///     <li><b><c>SERVER_VARTYPE_FLOAT</c></b></li>
///   </ul>
/// </remarks>
/// <returns>Returns the type of the SVar. See table below.</returns>
native GetSVarType(varname[]);

// Game

/// <summary>Set the name of the game mode, which appears in the server browser.</summary>
/// <param name="string">The gamemode name to display</param>
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

/// <summary>Ends the current gamemode.</summary>
/// <seealso name="OnGameModeExit"/>
native GameModeExit();
native SetWorldTime(hour);

/// <summary>Get the name of a weapon.</summary>
/// <param name="weaponid">The ID of the weapon to get the name of</param>
/// <param name="weapon">An array to store the weapon's name in, passed by reference</param>
/// <param name="len">The maximum length of the weapon name to store. Should be sizeof(name)</param>
/// <seealso name="GetPlayerWeapon"/>
/// <seealso name="AllowInteriorWeapons"/>
/// <seealso name="GivePlayerWeapon"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The weapon specified does not exist.
/// </returns>
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

/// <summary>Get the currently set gravity.</summary>
/// <seealso name="SetGravity"/>
/// <returns>The current set gravity (as a float).</returns>
native GetGravity();

/// <summary>Set the gravity for all players.</summary>
/// <param name="gravity">The value that the gravity should be set to (between -50 and 50)</param>
/// <seealso name="GetGravity"/>
/// <seealso name="SetWeather"/>
/// <seealso name="SetWorldTime"/>
/// <remarks>Default gravity is <b><c>0.008</c></b>.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even when it fails to execute if the gravity is out of the limits (lower than <b><c>-50.0</c></b> or higher than <b><c>+50.0</c></b>).</returns>
native SetGravity(Float:gravity);

/// <summary>This function will determine whether RCON admins will be teleported to their waypoint when they set one.</summary>
/// <param name="allow"><b><c>0</c></b> to disable and <b><c>1</c></b> to enable</param>
/// <remarks><b>This function, as of 0.3d, is deprecated. Please see <a href="#OnPlayerClickMap">OnPlayerClickMap</a>.</b></remarks>
/// <seealso name="IsPlayerAdmin"/>
/// <seealso name="AllowPlayerTeleport"/>
native AllowAdminTeleport(allow);

/// <summary>This function does not work in the current SA:MP version! </summary>
/// <seealso name="CreatePickup"/>
/// <seealso name="GivePlayerMoney"/>
/// <seealso name="OnPlayerDeath"/>
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

/// <summary>Set the maximum distance to display the names of players.</summary>
/// <param name="distance">The distance to set</param>
/// <seealso name="LimitGlobalChatRadius"/>
/// <seealso name="ShowNameTags"/>
/// <seealso name="ShowPlayerNameTagForPlayer"/>
/// <remarks>Default distance is <b>70</b> SA units</remarks>
native SetNameTagDrawDistance(Float:distance); // Distance at which nametags will start rendering on the client.

/// <summary>Disables the nametag Line-Of-Sight checking so that players can see nametags through objects.</summary>
/// <seealso name="ShowNameTags"/>
/// <seealso name="ShowPlayerNameTagForPlayer"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>This can not be reversed until the server restarts.</remarks>
native DisableNameTagLOS(); // Disables the nametag Line-Of-Sight checking

/// <summary>Set a radius limitation for the chat. Only players at a certain distance from the player will see their message in the chat. Also changes the distance at which a player can see other players on the map at the same distance.</summary>
/// <param name="chat_radius">The range in which players will be able to see chat</param>
/// <seealso name="SetNameTagDrawDistance"/>
/// <seealso name="SendPlayerMessageToPlayer"/>
/// <seealso name="SendPlayerMessageToAll"/>
/// <seealso name="OnPlayerText"/>
native LimitGlobalChatRadius(Float:chat_radius);

/// <summary>Set the player marker radius.</summary>
/// <param name="marker_radius">The radius that markers will show at</param>
/// <seealso name="ShowPlayerMarkers"/>
/// <seealso name="SetPlayerMarkerForPlayer"/>
/// <seealso name="LimitGlobalChatRadius"/>
/// <remarks>This Function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
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

/// <summary>Check if a player is an actual player or an NPC.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="ConnectNPC"/>
/// <seealso name="IsPlayerAdmin"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the player is an NPC, <b><c>0</c></b> if not.</returns>
native IsPlayerNPC(playerid);

// Admin

/// <summary>Check if a player is logged in as an RCON admin.</summary>
/// <param name="playerid">The ID of the player to check</param>
/// <seealso name="SendRconCommand"/>
/// <seealso name="OnRconLoginAttempt"/>
/// <returns><b><c>1</c></b> if the player is an RCON admin, <b><c>0</c></b> if not.</returns>
native IsPlayerAdmin(playerid);

/// <summary>Kicks a player from the server. They will have to quit the game and re-connect if they wish to continue playing.</summary>
/// <param name="playerid">The ID of the player to kick</param>
/// <seealso name="Ban"/>
/// <seealso name="BanEx"/>
/// <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Kick() (such as sending a message with <a href="#SendClientMessage">SendClientMessage</a>) will not reach the player. A timer must be used to delay the kick.</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if the function failed to execute (player specified doesn't exist).</returns>
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


/// <summary>Sends an RCON (Remote Console) command.</summary>
/// <param name="command">The RCON command to be executed</param>
/// <seealso name="IsPlayerAdmin"/>
/// <seealso name="OnRconCommand"/>
/// <seealso name="OnRconLoginAttempt"/>
/// <remarks>Does not support login, due to the lack of a 'playerid' parameter.</remarks>
/// <remarks>'password 0' will remove the server's password if one is set.</remarks>
/// <returns>This function always returns <b><c>1</c></b>.</returns>
/// <remarks>This function will result in <a href="#OnRconCommand">OnRconCommand</a> being called.</remarks>
native SendRconCommand(command[]);

/// <summary>Gets a player's network stats and saves them into a string.</summary>
/// <param name="playerid">The ID of the player you want to get the networkstats of</param>
/// <param name="retstr">The string to store the networkstats in, passed by reference</param>
/// <param name="retstr_size">The length of the string that should be stored</param>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3c R4</b> and will not work in earlier versions!</remarks>
/// <remarks>This function may not return accurate data when used under <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a> if the player has quit normally. It usually returns accurate data if the player has been kicked or has timed out.</remarks>
native GetPlayerNetworkStats(playerid, retstr[], retstr_size);

/// <summary>Gets the server's network stats and stores them in a string.</summary>
/// <param name="retstr">The string to store the network stats in, passed by reference</param>
/// <param name="retstr_size">The length of the string to be stored</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3c R4</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Example output:</b><p/>
///   <c>
///     Server Ticks: 200<p/>
///     Messages in Send buffer: 0<p/>
///     Messages sent: 142<p/>
///     Bytes sent: 8203<p/>
///     Acks sent: 11<p/>
///     Acks in send buffer: 0<p/>
///     Messages waiting for ack: 0<p/>
///     Messages resent: 0<p/>
///     Bytes resent: 0<p/>
///     Packetloss: 0.0%<p/>
///     Messages received: 54<p/>
///     Bytes received: 2204<p/>
///     Acks received: 0<p/>
///     Duplicate acks received: 0<p/>
///     Inst. KBits per second: 28.8<p/>
///     KBits per second sent: 10.0<p/>
///     KBits per second received: 2.7<p/>
///   </c>
/// </remarks>
/// <returns>This function always returns <b><c>1</c></b>.</returns>
native GetNetworkStats(retstr[], retstr_size);

/// <summary>Returns the SA-MP client version, as reported by the player.</summary>
/// <param name="playerid">The ID of the player to get the client version of</param>
/// <param name="version">The string to store the player's version in, passed by reference</param>
/// <param name="len">The maximum length of the version</param>
/// <seealso name="GetPlayerName"/>
/// <seealso name="GetPlayerPing"/>
/// <seealso name="GetPlayerIp"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>The string the version gets stored in will be empty if playerid is an NPC.</remarks>
/// <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure (if player specified doesn't exist).</returns>
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

/// <summary>Get the string value of a server variable.</summary>
/// <param name="const varname">The name of the string variable to get the value of</param>
/// <param name="buffer">An array into which to store the value, passed by reference</param>
/// <param name="len">The length of the string that should be stored</param>
/// <seealso name="GetServerVarAsInt"/>
/// <seealso name="GetServerVarAsBool"/>
/// <remarks>This function, as of <b>0.3.7 R2</b>, is deprecated. Please see <a href="#GetConsoleVarAsString">GetConsoleVarAsString</a></remarks>
/// <remarks>Using this function on anything other than a <b>string</b> (int, bool or float) or a <b>nonexistent</b> server variable, will <b>crash</b> your server! This is a bug.</remarks>
/// <remarks>Type 'varlist' in the server console to display a list of available server variables and their types.</remarks>
/// <remarks>When filterscripts or plugins is specified as the varname, this function only returns the name of the first specified filterscript or plugin. This is a bug.</remarks>
/// <returns>The length of the returned string. <b><c>0</c></b> if the specified server variable is not a string or doesn't exist.</returns>
native GetServerVarAsString(const varname[], buffer[], len);

/// <summary>Get the integer value of a server variable.</summary>
/// <param name="const varname">The name of the integer variable to get the value of</param>
/// <seealso name="GetServerVarAsString"/>
/// <seealso name="GetServerVarAsBool"/>
/// <remarks>This function, as of <b>0.3.7 R2</b>, is deprecated. Please see <a href="#GetConsoleVarAsInt">GetConsoleVarAsInt</a></remarks>
/// <remarks>Type 'varlist' in the server console to display a list of available server variables and their types.</remarks>
/// <returns>The value of the specified server variable. 0 if the specified server variable is not an integer or doesn't exist.</returns>
native GetServerVarAsInt(const varname[]);

/// <summary>Get the boolean value of a server variable.</summary>
/// <param name="const varname">The name of the boolean variable to get the value of</param>
/// <seealso name="GetServerVarAsString"/>
/// <seealso name="GetServerVarAsInt"/>
/// <remarks>This function, as of <b>0.3.7 R2</b>, is deprecated. Please see <a href="#GetConsoleVarAsBool">GetConsoleVarAsBool</a></remarks>
/// <remarks>Type 'varlist' in the server console to display a list of available server variables and their types.</remarks>
/// <returns>The value of the specified server variable. <b><c>0</c></b> if the specified server variable is not a boolean or doesn't exist.</returns>
native GetServerVarAsBool(const varname[]);
// These are the same 3 functions as above although they avoid the name ambiguity/conflict with the SVar system.

/// <summary>Get the string value of a console variable.</summary>
/// <param name="const varname">The name of the string variable to get the value of</param>
/// <param name="buffer">An array into which to store the value, passed by reference</param>
/// <param name="len">The length of the string that should be stored</param>
/// <seealso name="GetConsoleVarAsInt"/>
/// <seealso name="GetConsoleVarAsBool"/>
/// <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console variables and their types.</remarks>
/// <remarks>When filterscripts or plugins are specified as the varname, this function only returns the name of the first specified filterscript or plugin.</remarks>
/// <remarks>Using this function with anything other than a <b>string</b> (integer, boolean or float) will cause your server to crash. Using it with a nonexistent console variable will also cause your server to crash.</remarks>
/// <returns>The length of the returned string. <b><c>0</c></b> if the specified console variable is not a string or doesn't exist.</returns>
native GetConsoleVarAsString(const varname[], buffer[], len);

/// <summary>Get the integer value of a console variable.</summary>
/// <param name="const varname">The name of the integer variable to get the value of</param>
/// <seealso name="GetConsoleVarAsString"/>
/// <seealso name="GetConsoleVarAsBool"/>
/// <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console variables and their types.</remarks>
/// <returns>The value of the specified console variable. <b><c>0</c></b> if the specified console variable is not an integer or doesn't exist.</returns>
native GetConsoleVarAsInt(const varname[]);

/// <summary>Get the boolean value of a console variable.</summary>
/// <param name="const varname">The name of the boolean variable to get the value of</param>
/// <seealso name="GetConsoleVarAsString"/>
/// <seealso name="GetConsoleVarAsInt"/>
/// <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console variables and their types.</remarks>
/// <returns>The value of the specified console variable. <b><c>0</c></b> if the specified console variable is not a boolean or doesn't exist.</returns>
native GetConsoleVarAsBool(const varname[]);

// Extended admin network stats

/// <summary>Gets the tick rate (like FPS) of the server.</summary>
/// <seealso name="GetNetworkStats"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <returns>The server tick rate (per second). Returns <b><c>0</c></b> when the server is just started.</returns>
native GetServerTickRate();

/// <summary>Gets the amount of time (in milliseconds) that a player has been connected to the server for.</summary>
/// <param name="playerid">The ID of the player to get the connected time of</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>The return value is not reset to zero after changing the game mode (using the RCON command "gmx").</remarks>
/// <returns>This function returns the amount of time (in milliseconds) that a player has been connected to the server for. <b><c>0</c></b> is returned if the player is not connected.</returns>
native NetStats_GetConnectedTime(playerid);

/// <summary>Gets the number of messages the server has received from the player.</summary>
/// <param name="playerid">The ID of the player to get the data from</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <returns>This function returns the number of messages the server has received from the player. <b><c>0</c></b> is returned if the player is not connected.</returns>
native NetStats_MessagesReceived(playerid);

/// <summary>Gets the amount of data (in bytes) that the server has received from the player.</summary>
/// <param name="playerid">The ID of the player to get the data from</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <returns>This function returns the number of bytes the server has received from the player. <b><c>0</c></b> is returned if the player is not connected.</returns>
native NetStats_BytesReceived(playerid);

/// <summary>Gets the number of messages the server has sent to the player.</summary>
/// <param name="playerid">The ID of the player to get the data from</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <returns>The number of messages the server has sent to the player.</returns>
native NetStats_MessagesSent(playerid);

/// <summary>Gets the amount of data (in bytes) that the server has sent to the player.</summary>
/// <param name="playerid">The ID of the player to get the data from</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <returns>This function returns the number of bytes the server has sent to the player. <b><c>0</c></b> is returned if the player is not connected.</returns>
native NetStats_BytesSent(playerid);

/// <summary>Gets the number of messages the player has received in the last second.</summary>
/// <param name="playerid">The ID of the player to get the data from</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <returns>the number of messages the player has received in the last second.</returns>
native NetStats_MessagesRecvPerSecond(playerid);

/// <summary>Gets the packet loss percentage of a player. Packet loss means data the player is sending to the server is being lost (or vice-versa).</summary>
/// <param name="playerid">The ID of the player to get the data from</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>Anything greater than 0.0% should already be a cause of concern. Anything greater than 1.0% is outright bad.</remarks>
/// <remarks>This function has been found to be currently unreliable the output is not as expected when compared to the client. Therefore this function should not be used as a packet loss kicker. </remarks>
/// <remarks>A more accurate packetloss function can be found here: <a href="http://forum.sa-mp.com/showpost.php?p=2488911&amp;postcount=984">http://forum.sa-mp.com/showpost.php?p=2488911&amp;postcount=984</a></remarks>
/// <returns>The percentage packet loss as a float. <b><c>0.0</c></b> if player not connected.</returns>
native Float:NetStats_PacketLossPercent(playerid);

/// <summary>Gets the player's current connection status.</summary>
/// <param name="playerid">The ID of the player to get the connection status of</param>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_GetIpPort"/>
/// <seealso name="IsPlayerConnected"/>
/// <seealso name="OnPlayerConnect"/>
/// <seealso name="OnPlayerDisconnect"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Status:</b><p/>
///   <ul>
///     <li><b><c>0 - NO_ACTION</c></b></li>
///     <li><b><c>1 - DISCONNECT_ASAP</c></b></li>
///     <li><b><c>2 - DISCONNECT_ASAP_SILENTLY</c></b></li>
///     <li><b><c>3 - DISCONNECT_ON_NO_ACK</c></b></li>
///     <li><b><c>4 - REQUESTED_CONNECTION</c></b></li>
///     <li><b><c>5 - HANDLING_CONNECTION_REQUEST</c></b></li>
///     <li><b><c>6 - UNVERIFIED_SENDER</c></b></li>
///     <li><b><c>7 - SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET</c></b></li>
///     <li><b><c>8 - CONNECTED</c></b></li>
///   </ul>
/// </remarks>
/// <returns>The player's connection status, as an integer value.</returns>
native NetStats_ConnectionStatus(playerid);

/// <summary>Get a player's IP and port.</summary>
/// <param name="playerid">The ID of the player to get the IP and port of</param>
/// <param name="ip_port">A string array to store the IP and port in, passed by reference</param>
/// <param name="ip_port_len">The maximum length of the IP/port. 22 is recommended</param>
/// <seealso name="GetPlayerIp"/>
/// <seealso name="GetPlayerNetworkStats"/>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="NetStats_GetConnectedTime"/>
/// <seealso name="NetStats_MessagesReceived"/>
/// <seealso name="NetStats_BytesReceived"/>
/// <seealso name="NetStats_MessagesSent"/>
/// <seealso name="NetStats_BytesSent"/>
/// <seealso name="NetStats_MessagesRecvPerSecond"/>
/// <seealso name="NetStats_PacketLossPercent"/>
/// <seealso name="NetStats_ConnectionStatus"/>
/// <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
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

/// <summary>Sets the caption of a column in a menu.</summary>
/// <param name="menuid">ID of the menu to change</param>
/// <param name="column">The column (<b><c>0</c></b> or <b><c>1</c></b>) to set the header of</param>
/// <param name="text">The caption text for the column</param>
/// <seealso name="AddMenuItem"/>
/// <seealso name="CreateMenu"/>
/// <seealso name="OnPlayerSelectedMenuRow"/>
/// <remarks>Crashes when passed an invalid menu ID.</remarks>
/// <remarks>Note that you can add only 12 items with <a href="#AddMenuItem">AddMenuItem</a>. The 13th object of a menu would replace the header of the column which is correctly set with this function.</remarks>
native SetMenuColumnHeader(Menu:menuid, column, const columnheader[]);
native ShowMenuForPlayer(Menu:menuid, playerid);

/// <summary>Hides a menu for a player.</summary>
/// <param name="menuid">The ID of the menu to hide. Returned by <a href="#CreateMenu">CreateMenu</a> and passed to <a href="#OnPlayerSelectedMenuRow">OnPlayerSelectedMenuRow</a></param>
/// <param name="playerid">The ID of the player that the menu will be hidden for</param>
/// <seealso name="ShowMenuForPlayer"/>
/// <seealso name="AddMenuItem"/>
/// <seealso name="SetMenuColumnHeader"/>
/// <seealso name="CreateMenu"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute.
/// </returns>
native HideMenuForPlayer(Menu:menuid, playerid);

/// <summary>Check if a menu ID is vliad.</summary>
/// <param name="menuid">The menu to check for existance</param>
/// <seealso name="CreateMenu"/>
/// <seealso name="DestroyMenu"/>
/// <returns><b><c>true</c></b> if the menu is valid, otherwise <b><c>false</c></b>.</returns>
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

/// <summary>Gets the ID of the menu the player is currently viewing (shown by <a href="#ShowMenuForPlayer">ShowMenuForPlayer</a>).</summary>
/// <param name="playerid">The ID of the player to get the current menu of</param>
/// <seealso name="ShowMenuForPlayer"/>
/// <seealso name="HideMenuForPlayer"/>
/// <seealso name="CreateMenu"/>
/// <seealso name="DestroyMenu"/>
/// <seealso name="AddMenuItem"/>
/// <seealso name="OnPlayerSelectedMenuRow"/>
/// <seealso name="OnPlayerExitedMenu"/>
/// <remarks>Returns previous menu when none is displayed.</remarks>
/// <returns>The ID of the player's currently shown menu, or <b><c>INVALID_MENU (255)</c></b> if no menu shown.</returns>
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

/// <summary>Create a gangzone (colored radar area).</summary>
/// <param name="minx">The X coordinate for the west side of the gangzone</param>
/// <param name="miny">The Y coordinate for the south side of the gangzone</param>
/// <param name="maxx">The X coordinate for the east side of the gangzone</param>
/// <param name="maxy">The Y coordinate for the north side of the gangzone</param>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
/// <remarks>
///   There is a limit of 1024 gangzones.<p/>
///   Putting the parameters in the wrong order results in glitchy behavior. 
/// </remarks>
/// <remarks>This function merely CREATES the gangzone, you must use <a href="#GangZoneShowForPlayer">GangZoneShowForPlayer</a> or <a href="#GangZoneShowForAll">GangZoneShowForAll</a> to show it.</remarks>
/// <returns>The ID of the created zone, returns <b><c>-1</c></b> if not created.</returns>
native GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy);

/// <summary>Destroy a gangzone.</summary>
/// <param name="zone">The ID of the zone to destroy</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
native GangZoneDestroy(zone);

/// <summary>Show a gangzone for a player. Must be created with <a href="#GangZoneCreate">GangZoneCreate</a> first.</summary>
/// <param name="playerid">The ID of the player you would like to show the gangzone for.</param>
/// <param name="zone">The ID of the gang zone to show for the player. Returned by <a href="#GangZoneCreate">GangZoneCreate</a></param>
/// <param name="color">The color to show the gang zone, as an integer or hex in <b>RGBA</b> color format. Alpha transparency supported</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
/// <returns><b><c>1</c></b> if the gangzone was shown, otherwise <b><c>0</c></b> (non-existant).</returns>
native GangZoneShowForPlayer(playerid, zone, color);

/// <summary>Shows a gangzone with the desired color to all players.</summary>
/// <param name="zone">The ID of the gangzone to show (returned by <a href="# GangZoneCreate">GangZoneCreate</a>)</param>
/// <param name="color">The color to show the gang zone, as an integer or hex in <b>RGBA</b> color format. Alpha transparency supported</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. The gang zone was shown for all players.<p/>
///   <b><c>0</c></b>: The function failed to execute. The gangzone does not exist.
/// </returns>
native GangZoneShowForAll(zone, color);

/// <summary>Hides a gangzone for a player.</summary>
/// <param name="playerid">The ID of the player to hide the gangzone for</param>
/// <param name="zone">The ID of the zone to hide</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
native GangZoneHideForPlayer(playerid, zone);

/// <summary>GangZoneHideForAll hides a gangzone from all players.</summary>
/// <param name="zone">The zone to hide</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
native GangZoneHideForAll(zone);

/// <summary>Makes a gangzone flash for a player.</summary>
/// <param name="playerid">The ID of the player to flash the gangzone for</param>
/// <param name="zone">The ID of the zone to flash</param>
/// <param name="flashcolor">The color to flash the gang zone, as an integer or hex in <b>RGBA</b> color format. Alpha transparency supported</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
native GangZoneFlashForPlayer(playerid, zone, flashcolor);

/// <summary>GangZoneFlashForAll flashes a gangzone for all players.</summary>
/// <param name="zone">The zone to flash</param>
/// <param name="flashcolor">The color to flash the gang zone, as an integer or hex in <b>RGBA</b> color format. Alpha transparency supported</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <seealso name="GangZoneStopFlashForAll"/>
native GangZoneFlashForAll(zone, flashcolor);

/// <summary>Stops a gangzone flashing for a player.</summary>
/// <param name="playerid">The ID of the player to stop the gangzone flashing for</param>
/// <param name="zone">The ID of the gangzonezone to stop flashing</param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForAll"/>
native GangZoneStopFlashForPlayer(playerid, zone);

/// <summary>Stops a gangzone flashing for all players.</summary>
/// <param name="zone">The ID of the zone to stop flashing. Returned by <a href="#GangZoneCreate">GangZoneCreate</a></param>
/// <seealso name="GangZoneCreate"/>
/// <seealso name="GangZoneDestroy"/>
/// <seealso name="GangZoneShowForPlayer"/>
/// <seealso name="GangZoneShowForAll"/>
/// <seealso name="GangZoneHideForPlayer"/>
/// <seealso name="GangZoneHideForAll"/>
/// <seealso name="GangZoneFlashForPlayer"/>
/// <seealso name="GangZoneFlashForAll"/>
/// <seealso name="GangZoneStopFlashForPlayer"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is reported even if the gang zone wasn't flashing to begin with.<p/>
///   <b><c>0</c></b>: The function failed to execute. The gangzone specified does not exist.
/// </returns>
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

/// <summary>Fetch the GPCI of a user, this is linked to their SAMP/GTA on their computer.</summary>
/// <param name="playerid">The ID of the player to fetch their GPCI</param>
/// <param name="serial">String to store the fetched GPCI in</param>
/// <param name="len">Assigned size of the string, should use sizeof()</param>
/// <seealso name="GetNetworkStats"/>
/// <seealso name="GetPlayerNetworkStats"/>
/// <remarks>A player's GPCI is NOT UNIQUE, some players may have similar or the same GPCI, don't ban solely due to a GPCI match.</remarks>
/// <returns>This function will return the string value of a user's GPCI.</returns>
native gpci(playerid, serial[], len);
