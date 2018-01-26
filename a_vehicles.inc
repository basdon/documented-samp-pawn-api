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
native CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren=0);
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
native ChangeVehicleColor(vehicleid, color1, color2);
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
