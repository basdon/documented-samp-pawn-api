/*  SA-MP Object Functions
 *
 *  (c) Copyright 2005-2015, SA-MP Team
 *
 */

#if defined _objects_included
	#endinput
#endif
#define _objects_included
#pragma library objects

// Objects

/// <summary>Creates an object at specified coordinates in the game world.</summary>
/// <param name="modelid">The model to create</param>
/// <param name="X">The X coordinate to create the object at</param>
/// <param name="Y">The Y coordinate to create the object at</param>
/// <param name="Z">The Z coordinate to create the object at</param>
/// <param name="rX">The X rotation of the object</param>
/// <param name="rY">The Y rotation of the object</param>
/// <param name="rZ">The Z rotation of the object</param>
/// <param name="DrawDistance">The distance that San Andreas renders objects at. 0.0 will cause objects to render at their default distances. <b><c>Usable since 0.3b.</c></b> Limited to <b>300</b> prior to 0.3x (optional=<b><c>0.0</c></b>)</param>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="SetObjectMaterialText"/>
/// <seealso name="SetObjectMaterial"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="SetPlayerObjectMaterialText"/>
/// <seealso name="SetPlayerObjectMaterial"/>
/// <remarks>Objects that emit light (lampposts, police lights, bollard lights, neons etc.) that have a greater rotation than <b><c>16.26</c></b> degrees (or <b><c>-16.26</c></b>) on either the X or Y axis will stop shining. This effect also applies to light objects attached to other objects, players and vehicles. If a light object is attached to a car and the car is rotated over 16.26 degrees (like in a rollover), the object will also stop emitting light. This is a GTA:SA issue and is not caused by a bug in SA-MP.</remarks>
/// <remarks>In case the light is attached to another object, one fix for this is to set <b>SyncRotation</b> to false in <a href="#AttachObjectToObject">AttachObjectToObject</a>. This will ensure the light stays at 0 rotation. This would only really work for objects that consist ONLY of light, so wouldn't work for the police light for example. </remarks>
/// <remarks>There is a limit of <a href="http://wiki.sa-mp.com/wiki/Limits"><b><c>1000</c></b> objects (<b><c>MAX_OBJECTS</c></b>)</a>. To circumvent this limit, you can use a <a href="http://forum.sa-mp.com/showthread.php?t=102865">streamer</a></remarks>
/// <returns>The ID of the object that was created, or <b><c>INVALID_OBJECT_ID</c></b> if the object limit (<b><c>MAX_OBJECTS</c></b>) was reached.</returns>
native CreateObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:DrawDistance = 0.0);

/// <summary>Attach an object to a vehicle.</summary>
/// <param name="objectid">The ID of the object to attach to the vehicle. Note that this is an object ID, not a model ID. The object must be CreateObject created first</param>
/// <param name="vehicleid">The ID of the vehicle to attach the object to</param>
/// <param name="OffsetX">The X axis offset from the vehicle to attach the object to</param>
/// <param name="OffsetY">The Y axis offset from the vehicle to attach the object to</param>
/// <param name="OffsetZ">The Z axis offset from the vehicle to attach the object to</param>
/// <param name="RotX">The X rotation offset for the object</param>
/// <param name="RotY">The Y rotation offset for the object</param>
/// <param name="RotZ">The Z rotation offset for the object</param>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <remarks>This function was added in <b>SA-MP 0.3c</b> and will not work in earlier versions!</remarks>
/// <remarks>The object must be created first.</remarks>
/// <remarks>When the vehicle is destroyed or respawned, the attached objects won't be destroyed with it; they will remain stationary at the position the vehicle disappeared and be reattached to the next vehicle to claim the vehicle ID that the objects were attached to.</remarks>
native AttachObjectToVehicle(objectid, vehicleid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ);

/// <summary>You can use this function to attach objects to other objects. The objects will folow the main object.</summary>
/// <param name="objectid">The object to attach to another object</param>
/// <param name="attachtoid">The object to attach the object to</param>
/// <param name="OffsetX">The distance between the main object and the object in the X direction</param>
/// <param name="OffsetY">The distance between the main object and the object in the Y direction</param>
/// <param name="OffsetZ">The distance between the main object and the object in the Z direction</param>
/// <param name="RotX">The X rotation between the object and the main object</param>
/// <param name="RotY">The Y rotation between the object and the main object</param>
/// <param name="RotZ">The Z rotation between the object and the main object</param>
/// <param name="SyncRotation ">If set to <b><c>0</c></b>, objectid's rotation will not change with attachtoid's</param>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <ul>
///     <li>Both objects need to be created before attempting to attach them.</li>
///     <li>There is no player-object version of this function (AttachPlayerObjectToObject), meaning it will not be supported by streamers.</li>
///   </ul>
/// </remarks>
/// <returns>
/// <b><c>1</c></b>: The function executed successfully.<p/>
/// <b><c>0</c></b>: The function failed to execute. This means the first object (objectid) does not exist. There are no internal checks to verify that the second object (attachtoid) exists.
/// </returns>
native AttachObjectToObject(objectid, attachtoid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ, SyncRotation = 1);

/// <summary>Attach an object to a player.</summary>
/// <param name="objectid">The ID of the object to attach to the player</param>
/// <param name="playerid">The ID of the player to attach the object to</param>
/// <param name="OffsetX">The distance between the player and the object in the X direction</param>
/// <param name="OffsetY">The distance between the player and the object in the Y direction</param>
/// <param name="OffsetZ">The distance between the player and the object in the Z direction</param>
/// <param name="RotX">The X rotation between the object and the player</param>
/// <param name="RotY">The Y rotation between the object and the player</param>
/// <param name="RotZ">The Z rotation between the object and the player</param>
/// <seealso name="AttachObjectToVehicle"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="SetPlayerAttachedObject"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <returns>This function always returns <b><c>0</c></b>.</returns>
native AttachObjectToPlayer(objectid, playerid, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ);

native SetObjectPos(objectid, Float:X, Float:Y, Float:Z);

/// <summary>Get the position of an object.</summary>
/// <param name="objectid">The ID of the object to get the position of.</param>
/// <param name="X">A variable in which to store the X coordinate, passed by reference</param>
/// <param name="Y">A variable in which to store the Y coordinate, passed by reference</param>
/// <param name="Z">A variable in which to store the Z coordinate, passed by reference</param>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The specified object does not exist.
/// </returns>
native GetObjectPos(objectid, &Float:X, &Float:Y, &Float:Z);
native SetObjectRot(objectid, Float:RotX, Float:RotY, Float:RotZ);

/// <summary>Use this function to get the objects current rotation. The rotation is saved by reference in three RotX/RotY/RotZ variables.</summary>
/// <param name="objectid">The objectid of the object you want to get the rotation from</param>
/// <param name="RotX">The variable to store the X rotation, passed by reference</param>
/// <param name="RotY">The variable to store the Y rotation, passed by reference</param>
/// <param name="RotZ">The variable to store the Z rotation, passed by reference</param>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <returns>The object's rotation is stored in the referenced variables, not in the return value.</returns>
native GetObjectRot(objectid, &Float:RotX, &Float:RotY, &Float:RotZ);

/// <summary>Get the model ID of an object.</summary>
/// <param name="objectid">The ID of the object to get the model of</param>
/// <seealso name="GetPlayerObjectModel"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>The model ID of the object. <b><c>-1</c></b> if object does not exist.</returns>
native GetObjectModel(objectid);
native SetObjectNoCameraCol(objectid);

/// <summary>Checks if an object with the ID provided exists.</summary>
/// <param name="objectid">The ID of the object to check the existence of</param>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <remarks>This is to check if an object exists, not if a model is valid.</remarks>
/// <returns><b><c>1</c></b> if the object exists, <b><c>0</c></b> if not.</returns>
native IsValidObject(objectid);

/// <summary>Destroys (removes) an object that was created using <a href="#CreateObject">CreateObject</a>.</summary>
/// <param name="objectid">The ID of the object to destroy. Returned by <a href="#CreateObject">CreateObject</a></param>
/// <seealso name="CreateObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
native DestroyObject(objectid);
native MoveObject(objectid, Float:X, Float:Y, Float:Z, Float:Speed, Float:RotX = -1000.0, Float:RotY = -1000.0, Float:RotZ = -1000.0);
native StopObject(objectid);

/// <summary>Checks if the given objectid is moving.</summary>
/// <param name="objectid">The objectid you want to check if is moving</param>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="OnObjectMoved"/>
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the object is moving, <b><c>0</c></b> if not.</returns>
native IsObjectMoving(objectid);

/// <summary>Allows a player to edit an object (position and rotation) using their mouse on a GUI (Graphical User Interface).</summary>
/// <param name="playerid">The ID of the player that should edit the object</param>
/// <param name="objectid">The ID of the object to be edited by the player</param>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="EditPlayerObject"/>
/// <seealso name="EditAttachedObject"/>
/// <seealso name="SelectObject"/>
/// <seealso name="CancelEdit"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b> in vehicle) and moving your mouse.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. Success is reported when a non-existent object is specified, but nothing will happen.<p/>
///   <b><c>0</c></b>: The function failed to execute. The player is not connected.
/// </returns>
native EditObject(playerid, objectid);

/// <summary>Allows players to edit a player-object (position and rotation) with a GUI and their mouse.</summary>
/// <param name="playerid">The ID of the player that should edit the object</param>
/// <param name="objectid">The object to be edited by the player</param>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="EditObject"/>
/// <seealso name="EditAttachedObject"/>
/// <seealso name="SelectObject"/>
/// <seealso name="CancelEdit"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b> in vehicle) and moving your mouse.</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. Player or object not valid.
/// </returns>
native EditPlayerObject(playerid, objectid);
native SelectObject(playerid);

/// <summary>Cancel object edition mode for a player.</summary>
/// <param name="playerid">The ID of the player to cancel edition for</param>
/// <seealso name="SelectObject"/>
/// <seealso name="EditObject"/>
/// <seealso name="EditPlayerObject"/>
/// <seealso name="EditAttachedObject"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="MoveObject"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
native CancelEdit(playerid);

/// <summary>Creates an object which will be visible to only one player.</summary>
/// <param name="playerid">The ID of the player to create the object for</param>
/// <param name="modelid">The model to create</param>
/// <param name="X">The X coordinate to create the object at</param>
/// <param name="Y">The Y coordinate to create the object at</param>
/// <param name="Z">The Z coordinate to create the object at</param>
/// <param name="rX">The X rotation of the object</param>
/// <param name="rY">The Y rotation of the object</param>
/// <param name="rZ">The Z rotation of the object</param>
/// <param name="DrawDistance">The distance from which objects will appear to players. 0.0 will cause an object to render at its default distance. Leaving this parameter out will cause objects to be rendered at their default distance. The maximum usable distance is 300 in versions prior to 0.3x, in which drawdistance can be unlimited (optional=<b><c>0.0</c></b>)</param>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <remarks>The 'DrawDistance' parameter was added in <b>0.3b</b>. It must be left out in scripts for older versions of SA:MP.</remarks>
/// <returns>The ID of the object that was created, or <b><c>INVALID_OBJECT_ID</c></b> if the object limit (<b><c>MAX_OBJECTS</c></b>) was reached.</returns>
native CreatePlayerObject(playerid, modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:DrawDistance = 0.0);

/// <summary>Attach a player object to a vehicle.</summary>
/// <param name="playerid">The ID of the player the object was created for</param>
/// <param name="objectid">The ID of the object to attach to the vehicle</param>
/// <param name="vehicleid">The ID of the vehicle to attach the object to</param>
/// <param name="OffsetX">The X position offset for attachment</param>
/// <param name="OffsetY">The Y position offset for attachment</param>
/// <param name="OffsetZ">The Z position offset for attachment</param>
/// <param name="RotX">The X rotation offset for attachment</param>
/// <param name="RotY">The Y rotation offset for attachment</param>
/// <param name="RotZ">The Z rotation offset for attachment</param>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>You need to create the object before attempting to attach it to a vehicle.</remarks>
native AttachPlayerObjectToVehicle(playerid, objectid, vehicleid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:RotZ);

native SetPlayerObjectPos(playerid, objectid, Float:X, Float:Y, Float:Z);

/// <summary>Get the position of a player object (<a href="#CreatePlayerObject">CreatePlayerObject</a>).</summary>
/// <param name="playerid">The ID of the player whose player object to get the position of</param>
/// <param name="objectid">The object's id of which you want the current location</param>
/// <param name="X">A float variable in which to store the X coordinate, passed by reference</param>
/// <param name="Y">A float variable in which to store the Y coordinate, passed by reference</param>
/// <param name="Z">A float variable in which to store the Z coordinate, passed by reference</param>
/// <seealso name=""/>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name=""/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <returns>
/// 1: The function executed successfully.<p/>
/// 0: The function failed to execute. The player and/or the object don't exist.<p/>
/// The object's position is stored in the specified variables.
/// </returns>
native GetPlayerObjectPos(playerid, objectid, &Float:X, &Float:Y, &Float:Z);
native SetPlayerObjectRot(playerid, objectid, Float:RotX, Float:RotY, Float:RotZ);

/// <summary>Use this function to get the object's current rotation. The rotation is saved by reference in three RotX/RotY/RotZ variables.</summary>
/// <param name="playerid">The player you associated this object to</param>
/// <param name="objectid">The objectid of the object you want to get the rotation from</param>
/// <param name="RotX">The variable to store the X rotation, passed by reference</param>
/// <param name="RotY">The variable to store the Y rotation, passed by reference</param>
/// <param name="RotZ">The variable to store the Z rotation, passed by reference</param>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <returns>The object's rotation is stored in the specified variables.</returns>
native GetPlayerObjectRot(playerid, objectid, &Float:RotX, &Float:RotY, &Float:RotZ);

/// <summary>Retrieve the model ID of a player-object.</summary>
/// <param name="playerid">The ID of the player whose player-object to get the model of</param>
/// <param name="objectid">The ID of the player-object of which to retrieve the model ID</param>
/// <seealso name="GetObjectModel"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>The model ID of the player object. If the player or object don't exist, it will return <b><c>-1</c></b> or <b><c>0</c></b> if the player or object does not exist.</returns>
native GetPlayerObjectModel(playerid, objectid);
native SetPlayerObjectNoCameraCol(playerid, objectid);

/// <summary>Checks if the given object ID is valid for the given player.</summary>
/// <param name="playerid">The ID of the player whose player-object to validate</param>
/// <param name="objectid">The ID of the object to validate</param>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <returns><b><c>1</c></b> if the object exists, <b><c>0</c></b> if not.</returns>
native IsValidPlayerObject(playerid, objectid);

/// <summary>Destroy a player-object created using <a href="#CreatePlayerObject">CreatePlayerObject</a>.</summary>
/// <param name="playerid">The ID of the player whose player-object to destroy</param>
/// <param name="objectid">The ID of the player-object to destroy. Returned by <a href="#CreatePlayerObject">CreatePlayerObject</a></param>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
native DestroyPlayerObject(playerid, objectid);
native MovePlayerObject(playerid, objectid, Float:X, Float:Y, Float:Z, Float:Speed, Float:RotX = -1000.0, Float:RotY = -1000.0, Float:RotZ = -1000.0);
native StopPlayerObject(playerid, objectid);

/// <summary>Checks if the given player objectid is moving.</summary>
/// <param name="playerid">The ID of the player whose player-object is checked</param>
/// <param name="objectid">The player objectid you want to check if is moving</param>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="AttachPlayerObjectToPlayer"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="IsObjectMoving"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <seealso name="OnPlayerObjectMoved"/>
/// <remarks>This function was added in <b>SA-MP 0.3d</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>1</c></b> if the player object is moving, <b><c>0</c></b> if not.</returns>
native IsPlayerObjectMoving(playerid, objectid);

/// <summary>The same as AttachObjectToPlayer but for objects which were created for player.</summary>
/// <param name="objectplayer">The id of the player which is linked with the object</param>
/// <param name="objectid">The objectid you want to attach to the player</param>
/// <param name="attachid">The id of the player you want to attach to the object</param>
/// <param name="OffsetX">The distance between the player and the object in the X direction</param>
/// <param name="OffsetY">The distance between the player and the object in the Y direction</param>
/// <param name="OffsetZ">The distance between the player and the object in the Z direction</param>
/// <param name="RotX">The X rotation</param>
/// <param name="RotY">The Y rotation</param>
/// <param name="RotZ">The Z rotation</param>
/// <seealso name="CreatePlayerObject"/>
/// <seealso name="DestroyPlayerObject"/>
/// <seealso name="IsValidPlayerObject"/>
/// <seealso name="MovePlayerObject"/>
/// <seealso name="StopPlayerObject"/>
/// <seealso name="SetPlayerObjectPos"/>
/// <seealso name="SetPlayerObjectRot"/>
/// <seealso name="GetPlayerObjectPos"/>
/// <seealso name="GetPlayerObjectRot"/>
/// <seealso name="SetPlayerAttachedObject"/>
/// <seealso name="RemovePlayerAttachedObject"/>
/// <seealso name="IsPlayerAttachedObjectSlotUsed"/>
/// <seealso name="CreateObject"/>
/// <seealso name="DestroyObject"/>
/// <seealso name="IsValidObject"/>
/// <seealso name="MoveObject"/>
/// <seealso name="StopObject"/>
/// <seealso name="SetObjectPos"/>
/// <seealso name="SetObjectRot"/>
/// <seealso name="GetObjectPos"/>
/// <seealso name="GetObjectRot"/>
/// <seealso name="AttachObjectToPlayer"/>
/// <remarks><b>This function was removed in SA-MP 0.3.</b></remarks>
native AttachPlayerObjectToPlayer(objectplayer, objectid, attachplayer, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:rX, Float:rY, Float:rZ);

#define OBJECT_MATERIAL_SIZE_32x32		10
#define OBJECT_MATERIAL_SIZE_64x32		20
#define OBJECT_MATERIAL_SIZE_64x64		30
#define OBJECT_MATERIAL_SIZE_128x32		40
#define OBJECT_MATERIAL_SIZE_128x64		50
#define OBJECT_MATERIAL_SIZE_128x128	60
#define OBJECT_MATERIAL_SIZE_256x32		70
#define OBJECT_MATERIAL_SIZE_256x64		80
#define OBJECT_MATERIAL_SIZE_256x128	90
#define OBJECT_MATERIAL_SIZE_256x256	100
#define OBJECT_MATERIAL_SIZE_512x64		110
#define OBJECT_MATERIAL_SIZE_512x128	120
#define OBJECT_MATERIAL_SIZE_512x256	130
#define OBJECT_MATERIAL_SIZE_512x512	140

#define OBJECT_MATERIAL_TEXT_ALIGN_LEFT		0
#define OBJECT_MATERIAL_TEXT_ALIGN_CENTER	1
#define OBJECT_MATERIAL_TEXT_ALIGN_RIGHT	2

native SetObjectMaterial(objectid, materialindex, modelid, txdname[], texturename[], materialcolor=0);
native SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, txdname[], texturename[], materialcolor=0);

native SetObjectMaterialText(objectid, text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0);
native SetPlayerObjectMaterialText(playerid, objectid, text[], materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0);

native SetObjectsDefaultCameraCol(disable);
