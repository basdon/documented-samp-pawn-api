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
native IsVehicleStreamedIn(vehicleid, forplayerid);
native GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z);
native SetVehiclePos(vehicleid, Float:x, Float:y, Float:z);
native GetVehicleZAngle(vehicleid, &Float:z_angle);
native GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z);
native Float:GetVehicleDistanceFromPoint(vehicleid, Float:X, Float:Y, Float:Z);
native SetVehicleZAngle(vehicleid, Float:z_angle);
native SetVehicleParamsForPlayer(vehicleid,playerid,objective,doorslocked);
native ManualVehicleEngineAndLights();
native SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
native GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective);
native GetVehicleParamsSirenState(vehicleid);
native SetVehicleParamsCarDoors(vehicleid, driver, passenger, backleft, backright);
native GetVehicleParamsCarDoors(vehicleid, &driver, &passenger, &backleft, &backright);
native SetVehicleParamsCarWindows(vehicleid, driver, passenger, backleft, backright);
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
native IsTrailerAttachedToVehicle(vehicleid);
native GetVehicleTrailer(vehicleid);
native SetVehicleNumberPlate(vehicleid, numberplate[]);
native GetVehicleModel(vehicleid);
native GetVehicleComponentInSlot(vehicleid, slot); // There is 1 slot for each CARMODTYPE_*
native GetVehicleComponentType(component); // Find CARMODTYPE_* for component id
native RepairVehicle(vehicleid); // Repairs the damage model and resets the health
native GetVehicleVelocity(vehicleid, &Float:X, &Float:Y, &Float:Z);
native SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z);
native SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z);
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

native GetVehicleModelInfo(vehiclemodel, infotype, &Float:X, &Float:Y, &Float:Z);

// Virtual Worlds
native SetVehicleVirtualWorld(vehicleid, worldid);
native GetVehicleVirtualWorld(vehicleid);
