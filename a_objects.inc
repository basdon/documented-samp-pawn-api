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
native GetObjectPos(objectid, &Float:X, &Float:Y, &Float:Z);
native SetObjectRot(objectid, Float:RotX, Float:RotY, Float:RotZ);
native GetObjectRot(objectid, &Float:RotX, &Float:RotY, &Float:RotZ);
native GetObjectModel(objectid);
native SetObjectNoCameraCol(objectid);
native IsValidObject(objectid);
native DestroyObject(objectid);
native MoveObject(objectid, Float:X, Float:Y, Float:Z, Float:Speed, Float:RotX = -1000.0, Float:RotY = -1000.0, Float:RotZ = -1000.0);
native StopObject(objectid);
native IsObjectMoving(objectid);
native EditObject(playerid, objectid);
native EditPlayerObject(playerid, objectid);
native SelectObject(playerid);
native CancelEdit(playerid);
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
native GetPlayerObjectPos(playerid, objectid, &Float:X, &Float:Y, &Float:Z);
native SetPlayerObjectRot(playerid, objectid, Float:RotX, Float:RotY, Float:RotZ);
native GetPlayerObjectRot(playerid, objectid, &Float:RotX, &Float:RotY, &Float:RotZ);
native GetPlayerObjectModel(playerid, objectid);
native SetPlayerObjectNoCameraCol(playerid, objectid);
native IsValidPlayerObject(playerid, objectid);
native DestroyPlayerObject(playerid, objectid);
native MovePlayerObject(playerid, objectid, Float:X, Float:Y, Float:Z, Float:Speed, Float:RotX = -1000.0, Float:RotY = -1000.0, Float:RotZ = -1000.0);
native StopPlayerObject(playerid, objectid);
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
