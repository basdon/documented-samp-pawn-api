/*  SA-MP Vehicle Functions
 *
 *  (c) Copyright 2005-2012, SA-MP Team
 *
 */

#if defined _vehicles_included
	#endinput
#endif
#define _vehicles_included
#pragma library vehicles

#define CARMODTYPE_SPOILER		0
#define CARMODTYPE_HOOD			1
#define CARMODTYPE_ROOF			2
#define CARMODTYPE_SIDESKIRT	3
#define CARMODTYPE_LAMPS		4
#define CARMODTYPE_NITRO		5
#define CARMODTYPE_EXHAUST		6
#define CARMODTYPE_WHEELS		7
#define CARMODTYPE_STEREO		8
#define CARMODTYPE_HYDRAULICS	9
#define CARMODTYPE_FRONT_BUMPER	10
#define CARMODTYPE_REAR_BUMPER	11
#define CARMODTYPE_VENT_RIGHT	12
#define CARMODTYPE_VENT_LEFT	13

#define VEHICLE_PARAMS_UNSET	-1
#define VEHICLE_PARAMS_OFF		0
#define VEHICLE_PARAMS_ON		1

// Vehicle

/// <summary>Creates a vehicle in the world. Can be used in place of <a href="#AddStaticVehicleEx">AddStaticVehicleEx</a> at any time in the script.</summary>
/// <param name="vehicletype">The <a href="http://wiki.sa-mp.com/wiki/Vehicle_Models">model</a> for the vehicle</param>
/// <param name="X">The X coordinate for the vehicle</param>
/// <param name="Y">The Y coordinate for the vehicle</param>
/// <param name="Z">The Z coordinate for the vehicle</param>
/// <param name="rotation">The facing angle for the vehicle</param>
/// <param name="color1">The primary <a href="http://wiki.sa-mp.com/wiki/Color_ID">color ID</a></param>
/// <param name="color2">The secondary <a href="http://wiki.sa-mp.com/wiki/Color_ID">color ID</a></param>
/// <param name="respawn_delay">The delay until the car is respawned without a driver in <b>seconds</b>. Using <b><c>-1</c></b> will prevent the vehicle from respawning</param>
/// <param name="addsiren"><b>Added in 0.3.7; will not work in earlier versions</b>. Enables the vehicle to have a siren, providing the vehicle has a horn (optional=<b><c>0</c></b>)</param>
/// <seealso name="DestroyVehicle"/>
/// <seealso name="AddStaticVehicle"/>
/// <seealso name="AddStaticVehicleEx"/>
/// <seealso name="GetVehicleParamsSirenState"/>
/// <seealso name="OnVehicleSpawn"/>
/// <seealso name="OnVehicleSirenStateChange"/>
/// <remarks>Trains can only be added with AddStaticVehicle and AddStaticVehicleEx.</remarks>
/// <returns>
///   The vehicle ID of the vehicle created (<b><c>1</c></b> to <b><c>MAX_VEHICLES</c></b>).<p/>
///   <b><c>INVALID_VEHICLE_ID (65535)</c></b> if vehicle was not created (vehicle limit reached or invalid vehicle model ID passed).
/// </returns>
native CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren=0);

/// <summary>Destroy a vehicle. It will disappear instantly.</summary>
/// <param name="vehicleid">The ID of the vehicle to destroy</param>
/// <seealso name="CreateVehicle"/>
/// <seealso name="RemovePlayerFromVehicle"/>
/// <seealso name="SetVehicleToRespawn"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The vehicle does not exist.
/// </returns>
native DestroyVehicle(vehicleid);

/// <summary>Checks if a vehicle is streamed in for a player. Only nearby vehicles are streamed in (visible) for a player.</summary>
/// <param name="vehicleid">The ID of the vehicle to check</param>
/// <param name="forplayerid">The ID of the player to check</param>
/// <seealso name="IsPlayerStreamedIn"/>
/// <seealso name="OnVehicleStreamIn"/>
/// <seealso name="OnVehicleStreamOut"/>
/// <seealso name="OnPlayerStreamIn"/>
/// <seealso name="OnPlayerStreamOut"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>
///   <b><c>0</c></b>: Vehicle is not streamed in for the player, or the function failed to execute (player and/or vehicle do not exist).<p/>
///   <b><c>1</c></b>: Vehicle is streamed in for the player.
/// </returns>
native IsVehicleStreamedIn(vehicleid, forplayerid);

/// <summary>Gets the position of a vehicle.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the position of</param>
/// <param name="x">A float variable in which to store the X coordinate, passed by reference</param>
/// <param name="y">A float variable in which to store the Y coordinate, passed by reference</param>
/// <param name="z">A float variable in which to store the Z coordinate, passed by reference</param>
/// <seealso name="GetVehicleDistanceFromPoint"/>
/// <seealso name="SetVehiclePos"/>
/// <seealso name="GetVehicleZAngle"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. The vehicle specified does not exist.
/// </returns>
native GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z);
native SetVehiclePos(vehicleid, Float:x, Float:y, Float:z);

/// <summary>Get the rotation of a vehicle on the Z axis (yaw).</summary>
/// <param name="vehicleid">The ID of the vehicle to get the Z angle of</param>
/// <param name="z_angle">A float variable in which to store the Z rotation, passed by reference</param>
/// <seealso name="GetVehicleRotationQuat"/>
/// <seealso name="GetVehicleRotation"/>
/// <seealso name="SetVehicleZAngle"/>
/// <seealso name="GetVehiclePos"/>
/// <seealso name="GetPlayerFacingAngle"/>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the vehicle does not exist.
/// </returns>
native GetVehicleZAngle(vehicleid, &Float:z_angle);

/// <summary>Returns a vehicle's rotation on all axes as a quaternion.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the rotation of</param>
/// <param name="w">A float variable in which to store the first quaternion angle, passed by reference</param>
/// <param name="x">A float variable in which to store the second quaternion angle, passed by reference</param>
/// <param name="y">A float variable in which to store the third quaternion angle, passed by reference</param>
/// <param name="z">A float variable in which to store the fourth quaternion angle, passed by reference</param>
/// <seealso name="GetVehicleZAngle"/>
/// <remarks>This function was added in <b>SA-MP 0.3b</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>To euler:</b><p/>
///   <code>
///     //GetVehicleRotation Created by IllidanS4<p/>
///     stock GetVehicleRotation(vehicleid,&amp;Float:rx,&amp;Float:ry,&amp;Float:rz){<p/>
///     &#9;new Float:qw,Float:qx,Float:qy,Float:qz;<p/>
///     &#9;GetVehicleRotationQuat(vehicleid,qw,qx,qy,qz);<p/>
///     &#9;rx = asin(2*qy*qz-2*qx*qw);<p/>
///     &#9;ry = -atan2(qx*qz+qy*qw,0.5-qx*qx-qy*qy);<p/>
///     &#9;rz = -atan2(qx*qy+qz*qw,0.5-qx*qx-qz*qz);<p/>
///     }
///   </code>
/// </remarks>
/// <remarks>There is no 'set' variation of this function; you can not SET a vehicle's rotation (apart from the <a href="#SetVehicleZAngle">Z angle</a>) </remarks>
/// <remarks>This function may return incorrect values for unoccupied vehicles. The reason is that the third row of the vehicle's internal rotation matrix gets corrupted if it gets updated while unoccupied. </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the vehicle specified does not exist.
/// </returns>
native GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z);

/// <summary>This function can be used to calculate the distance (as a float) between a vehicle and another map coordinate. This can be useful to detect how far a vehicle away is from a location.</summary>
/// <param name="vehicleid">The ID of the vehicle to calculate the distance for</param>
/// <param name="X">The X map coordinate</param>
/// <param name="Y">The Y map coordinate</param>
/// <param name="Z">The Z map coordinate</param>
/// <seealso name="GetPlayerDistanceFromPoint"/>
/// <seealso name="GetVehiclePos"/>
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns>A float containing the distance from the point specified in the coordinates.</returns>
native Float:GetVehicleDistanceFromPoint(vehicleid, Float:X, Float:Y, Float:Z);
native SetVehicleZAngle(vehicleid, Float:z_angle);
native SetVehicleParamsForPlayer(vehicleid,playerid,objective,doorslocked);
native ManualVehicleEngineAndLights();
native SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
native GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective);

/// <summary>Returns a vehicle's siren state (on/off).</summary>
/// <param name="vehicleid">The ID of the vehicle to get the siren state of</param>
/// <seealso name="OnVehicleSirenStateChange"/>
/// <remarks>This function was added in <b>SA-MP 0.3c R3</b> and will not work in earlier versions!</remarks>
/// <returns><b><c>-1</c></b> if unset (off), <b><c>0</c></b> if off, <b><c>1</c></b> if on</returns>
native GetVehicleParamsSirenState(vehicleid);
native SetVehicleParamsCarDoors(vehicleid, driver, passenger, backleft, backright);

/// <summary>Allows you to retrieve the current state of a vehicle's doors.</summary>
/// <param name="vehicleid">The ID of the vehicle</param>
/// <param name="driver">The integer to save the state of the driver's door to</param>
/// <param name="passenger">The integer to save the state of the passenger's door to</param>
/// <param name="backleft">The integer to save the state of the rear left door to (if available)</param>
/// <param name="backright">The integer to save the state of the rear right door to (if available)</param>
/// <seealso name="SetVehicleParamsCarDoors"/>
/// <seealso name="SetVehicleParamsCarWindows"/>
/// <seealso name="GetVehicleParamsCarWindows"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>The values returned in each variable are as follows: <b><c>-1</c></b> if not set, <b><c>0</c></b> if closed, <b><c>1</c></b> if open.</remarks>
native GetVehicleParamsCarDoors(vehicleid, &driver, &passenger, &backleft, &backright);
native SetVehicleParamsCarWindows(vehicleid, driver, passenger, backleft, backright);

/// <summary>Allows you to retrieve the current state of a vehicle's windows.</summary>
/// <param name="vehicleid">The ID of the vehicle</param>
/// <param name="driver">The integer to save the state of the drivers window to</param>
/// <param name="passenger">The integer to save the state of the passengers window to</param>
/// <param name="backleft">The integer to save the state of the rear left window to (if available)</param>
/// <param name="backright">The integer to save the state of the rear right window to (if available)</param>
/// <seealso name="SetVehicleParamsCarWindows"/>
/// <seealso name="GetVehicleParamsCarDoors"/>
/// <seealso name="SetVehicleParamsCarDoors"/>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <remarks>The values returned in each variable are as follows: <b><c>-1</c></b> if not set, <b><c>0</c></b> if closed, <b><c>1</c></b> if open.</remarks>
/// <returns>The vehicle's windows state is stored in the specified variables.</returns>
native GetVehicleParamsCarWindows(vehicleid, &driver, &passenger, &backleft, &backright);
native SetVehicleToRespawn(vehicleid);
native LinkVehicleToInterior(vehicleid, interiorid);

/// <summary>Adds a 'component' (often referred to as a 'mod' (modification)) to a vehicle. Valid components can be found <a href="http://wiki.sa-mp.com/wiki/Car_Component_ID">here</a>.</summary>
/// <param name="vehicleid">The ID of the vehicle to add the component to. Not to be confused with <a href="http://wiki.sa-mp.com/wiki/Confuse_modelid">modelid</a></param>
/// <param name="componentid">The <a href="http://wiki.sa-mp.com/wiki/Car_Component_ID">ID of the component</a> to add to the vehicle</param>
/// <returns>
///   <ul>
///     <li><b><c>0</c></b> - The component was not added because the vehicle does not exist.</li>
///     <li><b><c>1</c></b> - The component was successfully added to the vehicle.</li>
///   </ul>
/// </returns>
/// <remarks>Using an invalid <a href="http://wiki.sa-mp.com/wiki/Car_Component_ID">component ID</a> crashes the player's game. There are no internal checks for this.</remarks>
/// <seealso name="RemoveVehicleComponent"/>
/// <seealso name="GetVehicleComponentInSlot"/>
/// <seealso name="GetVehicleComponentType"/>
/// <seealso name="OnVehicleMod"/>
/// <seealso name="OnEnterExitModShop"/>
native AddVehicleComponent(vehicleid, componentid);

native RemoveVehicleComponent(vehicleid, componentid);

/// <summary>Change a vehicle's primary and secondary colors.</summary>
/// <param name="vehicleid">The ID of the vehicle to change the colors of</param>
/// <param name="color1">The new vehicle's primary <a href="http://wiki.sa-mp.com/wiki/Color_ID">Color ID</a></param>
/// <param name="color2">The new vehicle's secondary <a href="http://wiki.sa-mp.com/wiki/Color_ID">Color ID</a></param>
/// <seealso name="ChangeVehiclePaintjob"/>
/// <seealso name="OnVehicleRespray"/>
/// <remarks>Some vehicles have only a primary color and some can not have the color changed at all. A few (cement, squallo) have 4 colors, of which 2 can not be changed in SA:MP</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully. The vehicle's color was successfully changed.<p/>
///   <b><c>0</c></b>: The function failed to execute. The vehicle does not exist.
/// </returns>
native ChangeVehicleColor(vehicleid, color1, color2);

/// <summary>Change a vehicle's paintjob (for plain colors see <a href="#ChangeVehicleColor">ChangeVehicleColor</a>).</summary>
/// <param name="vehicleid">The ID of the vehicle to change the paintjob of</param>
/// <param name="paintjobid">The ID of the Paintjob to apply. Use <b><c>3</c></b> to remove a paintjob</param>
/// <seealso name="ChangeVehicleColor"/>
/// <seealso name="OnVehiclePaintjob"/>
/// <remarks>
///   <b>Known Bugs:</b><p/>
///   This function calls <a href="#OnVehicleRespray">OnVehicleRespray</a>.<p/>
///   Vehicles change their color to white anymore when a paintjob is removed.
/// </remarks>
/// <returns>This function always returns <b><c>1</c></b> (success), even if the vehicle passed is not created.</returns>
native ChangeVehiclePaintjob(vehicleid, paintjobid);

native SetVehicleHealth(vehicleid, Float:health);

/// <summary>Get the health of a vehicle.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the health of</param>
/// <param name="health">A float variable in which to store the vehicle's health, passed by reference</param>
/// <seealso name="SetVehicleHealth"/>
/// <seealso name="GetPlayerHealth"/>
/// <seealso name="GetPlayerArmour"/>
/// <remarks>Full vehicle health is <b><c>1000</c></b>, however higher values are possible and increase the health of the vehicle.</remarks>
/// <remarks>
///   <b>Health:</b><p/>
///   <ul>
///     <li>&gt; 650 - undamaged</li>
///     <li>650-550 - white Smoke</li>
///     <li>550-390 - grey Smoke</li>
///     <li>390-250 - black Smoke</li>
///     <li>&lt; 250 - on fire (will explode seconds later)</li>
///   </ul>
/// </remarks>
/// <returns>
///   <b><c>1</c></b> - success.<p/>
///   <b><c>0</c></b> - failure (invalid vehicle ID).<p/>
/// </returns>
native GetVehicleHealth(vehicleid, &Float:health);

/// <summary>Attach a vehicle to another vehicle as a trailer.</summary>
/// <param name="trailerid">The ID of the vehicle that will be pulled</param>
/// <param name="vehicleid">The ID of the vehicle that will pull the trailer</param>
/// <seealso name="DetachTrailerFromVehicle"/>
/// <seealso name="IsTrailerAttachedToVehicle"/>
/// <seealso name="GetVehicleTrailer"/>
/// <remarks>This will only work if both vehicles are streamed in for a player (check <a href="#IsVehicleStreamedIn">IsVehicleStreamedIn</a>).</remarks>
/// <returns>This function always returns <b><c>1</c></b>, even if neither of the vehicle IDs passed are valid.</returns>
native AttachTrailerToVehicle(trailerid, vehicleid);

/// <summary>Detach the connection between a vehicle and its trailer, if any.</summary>
/// <param name="vehicleid">ID of the pulling vehicle</param>
/// <seealso name="AttachTrailerToVehicle"/>
/// <seealso name="IsTrailerAttachedToVehicle"/>
/// <seealso name="GetVehicleTrailer"/>
native DetachTrailerFromVehicle(vehicleid);

/// <summary>Checks if a vehicle has a trailer attached to it. Use <a href="#GetVehicleTrailer">GetVehicleTrailer</a> to get the vehicle ID of the trailer (if any).</summary>
/// <param name="vehicleid">The ID of the vehicle to check for trailers</param>
/// <seealso name="GetVehicleTrailer"/>
/// <seealso name="AttachTrailerToVehicle"/>
/// <seealso name="DetachTrailerFromVehicle"/>
/// <returns><b><c>1</c></b> if the vehicle has a trailer attached, <b><c>0</c></b> if not.</returns>
native IsTrailerAttachedToVehicle(vehicleid);

/// <summary>Get the ID of the trailer attached to a vehicle.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the trailer of</param>
/// <seealso name="AttachTrailerToVehicle"/>
/// <seealso name="DetachTrailerFromVehicle"/>
/// <seealso name="IsTrailerAttachedToVehicle"/>
/// <returns>The vehicle ID of the trailer or <b><c>0</c></b> if no trailer is attached.</returns>
native GetVehicleTrailer(vehicleid);
native SetVehicleNumberPlate(vehicleid, numberplate[]);

/// <summary>Gets the <a href="http://wiki.sa-mp.com/wiki/Vehicle_Models">model ID</a> of a vehicle.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the model of</param>
/// <seealso name="GetPlayerVehicleID"/>
/// <seealso name="GetVehiclePos"/>
/// <seealso name="GetVehicleZAngle"/>
/// <seealso name="GetPlayerVehicleSeat"/>
/// <returns>The vehicle's <a href="http://wiki.sa-mp.com/wiki/Vehicle_Models">model ID</a>, or <b><c>0</c></b> if the vehicle doesn't exist.</returns>
native GetVehicleModel(vehicleid);

/// <summary>Retrieves the installed component ID (modshop mod(ification)) on a vehicle in a specific slot.</summary>
/// <param name="vehicleid">The ID of the vehicle to check for the component</param>
/// <param name="slot">The component slot to check for components (see below)</param>
/// <seealso name="AddVehicleComponent"/>
/// <seealso name="GetVehicleComponentType"/>
/// <seealso name="OnVehicleMod"/>
/// <seealso name="OnEnterExitModShop"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Slots:</b><p/>
///   <c>
///     CARMODTYPE_SPOILER
///     CARMODTYPE_HOOD
///     CARMODTYPE_ROOF
///     CARMODTYPE_SIDESKIRT
///     CARMODTYPE_LAMPS
///     CARMODTYPE_NITRO
///     CARMODTYPE_EXHAUST
///     CARMODTYPE_WHEELS
///     CARMODTYPE_STEREO
///     CARMODTYPE_HYDRAULICS
///     CARMODTYPE_FRONT_BUMPER
///     CARMODTYPE_REAR_BUMPER
///     CARMODTYPE_VENT_RIGHT
///     CARMODTYPE_VENT_LEFT
///   </c>
/// </remarks>
/// <remarks>
///   <b>Known Bugs:</b><p/>
///   <ul>
///     <li>Doesn't work for <b><c>CARMODTYPE_STEREO</c></b>.</li>
///     <li>Both front bull bars and front bumper components are saved in the <b><c>CARMODTYPE_FRONT_BUMPER</c></b> slot. If a vehicle has both of them installed, this function will only return the one which was installed last.</li>
///     <li>Both rear bull bars and rear bumper components are saved in the <b><c>CARMODTYPE_REAR_BUMPER</c></b> slot. If a vehicle has both of them installed, this function will only return the one which was installed last.</li>
///     <li>Both left side skirt and right side skirt are saved in the <b><c>CARMODTYPE_SIDESKIRT</c></b> slot. If a vehicle has both of them installed, this function will only return the one which was installed last. </li>
///   </ul>
/// </remarks>
/// <returns>The ID of the component installed in the specified slot. Returns <b><c>0</c></b> if no component in specified vehicle's specified slot, or if vehicle doesn't exist.</returns>
native GetVehicleComponentInSlot(vehicleid, slot); // There is 1 slot for each CARMODTYPE_*

/// <summary>Find out what type of component a certain ID is.</summary>
/// <param name="component">The component ID to check</param>
/// <seealso name="AddVehicleComponent"/>
/// <seealso name="RemoveVehicleComponent"/>
/// <seealso name="GetVehicleComponentInSlot"/>
/// <seealso name="OnVehicleMod"/>
/// <seealso name="OnEnterExitModShop"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <returns>The component slot ID of the specified component or <b><c>-1</c></b> if the component is invalid.</returns>
native GetVehicleComponentType(component); // Find CARMODTYPE_* for component id
native RepairVehicle(vehicleid); // Repairs the damage model and resets the health

/// <summary>Get the velocity of a vehicle on the X, Y and Z axes.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the velocity of</param>
/// <param name="X">A float variable in to which to store the vehicle's X velocity, passed by reference</param>
/// <param name="Y">A float variable in to which to store the vehicle's Y velocity, passed by reference</param>
/// <param name="Z">A float variable in to which to store the vehicle's Z velocity, passed by reference</param>
/// <seealso name="GetPlayerVelocity"/>
/// <seealso name="SetVehicleVelocity"/>
/// <seealso name="SetPlayerVelocity"/>
/// <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>Multiply vector with <b><c>250.66667</c></b> for kmph or <b><c>199.416667</c></b> for mph or something...</remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the vehicle specified does not exist.<p/>
/// </returns>
native GetVehicleVelocity(vehicleid, &Float:X, &Float:Y, &Float:Z);
native SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z);
native SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z);

/// <summary>Retrieve the damage statuses of a vehicle.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the damage statuses of</param>
/// <param name="panels">A variable to store the panel damage data in, passed by reference</param>
/// <param name="doors">A variable to store the door damage data in, passed by reference</param>
/// <param name="lights">A variable to store the light damage data in, passed by reference</param>
/// <param name="tires">A variable to store the tire damage data in, passed by reference</param>
/// <seealso name="UpdateVehicleDamageStatus"/>
/// <seealso name="SetVehicleHealth"/>
/// <seealso name="GetVehicleHealth"/>
/// <seealso name="RepairVehicle"/>
/// <seealso name="OnVehicleDamageStatusUpdate"/>
/// <remarks>This Callback was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Door states:</b><p/>
///   <ul>
///     <li><b><c>0x000000FF</c></b> - hood</li>
///     <li><b><c>0x0000FF00</c></b> - trunk</li>
///     <li><b><c>0x00FF0000</c></b> - drivers door</li>
///     <li><b><c>0xFF000000</c></b> - co-drivers door</li>
///     <li>byte meaning:</li>
///     <li><b><c>0x1</c></b> - is opened</li>
///     <li><b><c>0x2</c></b> - is damaged</li>
///     <li><b><c>0x4</c></b> - is removed</li>
///     <li>other bytes are unused</li>
///   </ul>
/// </remarks>
/// <remarks>
///   <b>Light states:</b><p/>
///   <ul>
///     <li><b><c>0x01</c></b> - front left broken</li>
///     <li><b><c>0x04</c></b> - front right broken</li>
///     <li><b><c>0x40</c></b> - back both broken</li>
///   </ul>
/// </remarks>
/// <remarks>
///   <b>Tire states:</b><p/>
///   <ul>
///     <li><b><c>0x1</c></b> - back right popped</li>
///     <li><b><c>0x2</c></b> - front right popped</li>
///     <li><b><c>0x4</c></b> - back left popped</li>
///     <li><b><c>0x8</c></b> - front left popped</li>
///     <li>only check the right states for bikes</li>
///   </ul>
/// </remarks>
/// <returns>
///   <b><c>1</c></b>: The function executed successfully.<p/>
///   <b><c>0</c></b>: The function failed to execute. This means the vehicle specified does not exist.
/// </returns>
native GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires);
native UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);

#define VEHICLE_MODEL_INFO_SIZE				1
#define VEHICLE_MODEL_INFO_FRONTSEAT		2
#define VEHICLE_MODEL_INFO_REARSEAT			3
#define VEHICLE_MODEL_INFO_PETROLCAP		4
#define VEHICLE_MODEL_INFO_WHEELSFRONT		5
#define VEHICLE_MODEL_INFO_WHEELSREAR		6
#define VEHICLE_MODEL_INFO_WHEELSMID		7
#define VEHICLE_MODEL_INFO_FRONT_BUMPER_Z	8
#define VEHICLE_MODEL_INFO_REAR_BUMPER_Z	9


/// <summary>Retrieve information about a specific vehicle model such as the size or position of seats.</summary>
/// <param name="vehiclemodel">The vehicle <a href="http://wiki.sa-mp.com/wiki/Vehicles:All">model</a> to get info of</param>
/// <param name="infotype">The type of information to retrieve</param>
/// <param name="X">A float to store the X value</param>
/// <param name="Y">A float to store the Y value</param>
/// <param name="Z">A float to store the Z value</param>
/// <seealso name="GetVehicleModel"/>
/// <remarks>This function was added in <b>SA-MP 0.3e</b> and will not work in earlier versions!</remarks>
/// <remarks>
///   <b>Information types:</b><p/>
///   <ul>
///     <li><b><c>VEHICLE_MODEL_INFO_SIZE</c></b> - vehicle size</li>
///     <li><b><c>VEHICLE_MODEL_INFO_FRONTSEAT</c></b> - position of the front seat</li>
///     <li><b><c>VEHICLE_MODEL_INFO_REARSEAT</c></b> - position of the rear seat</li>
///     <li><b><c>VEHICLE_MODEL_INFO_PETROLCAP</c></b> - position of the fuel cap</li>
///     <li><b><c>VEHICLE_MODEL_INFO_WHEELSFRONT</c></b> - position of the front wheels</li>
///     <li><b><c>VEHICLE_MODEL_INFO_WHEELSREAR</c></b> - position of the rear wheels</li>
///     <li><b><c>VEHICLE_MODEL_INFO_WHEELSMID</c></b> - position of the middle wheels (applies to vehicles with 3 axes)</li>
///     <li><b><c>VEHICLE_MODEL_INFO_FRONT_BUMPER_Z</c></b> - height of the front bumper</li>
///     <li><b><c>VEHICLE_MODEL_INFO_REAR_BUMPER_Z </c></b> - height of the rear bumper</li>
///   </ul>
/// </remarks>
native GetVehicleModelInfo(vehiclemodel, infotype, &Float:X, &Float:Y, &Float:Z);

// Virtual Worlds
native SetVehicleVirtualWorld(vehicleid, worldid);

/// <summary>Get the virtual world of a vehicle.</summary>
/// <param name="vehicleid">The ID of the vehicle to get the virtual world of</param>
/// <seealso name="SetVehicleVirtualWorld"/>
/// <seealso name="GetPlayerVirtualWorld"/>
/// <returns>The virtual world that the vehicle is in.</returns>
native GetVehicleVirtualWorld(vehicleid);

/// <summary>Check if a vehicle is created.</summary>
/// <param name="vehicleid">The vehicle to check for existance</param>
/// <seealso name="GetPlayerVehicleID"/>
/// <seealso name="GetVehicleModel"/>
/// <returns><b><c>true</c></b> if the vehicle exists, otherwise <b><c>false</c></b>.</returns>
native IsValidVehicle(vehicleid);
