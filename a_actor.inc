/*  SA-MP Actor Functions
 *
 *  (c) Copyright 2015, SA-MP Team
 *
 */

#if defined _actor_included
	#endinput
#endif
#define _actor_included
#pragma library actors

native CreateActor(modelid, Float:X, Float:Y, Float:Z, Float:Rotation);
native DestroyActor(actorid);

native IsActorStreamedIn(actorid, forplayerid);

native SetActorVirtualWorld(actorid, vworld);
native GetActorVirtualWorld(actorid);

/// <summary>Apply an animation to an actor.</summary>
/// <param name="actorid">The ID of the actor to apply the animation to</param>
/// <param name="animlib">The animation library from which to apply an animation</param>
/// <param name="animname">The name of the animation to apply, within the specified library</param>
/// <param name="fDelta">The speed to play the animation (use 4.1)</param>
/// <param name="loop">If set to <b><c>1</c></b>, the animation will loop. If set to <b><c>0</c></b>, the animation will play once</param>
/// <param name="lockx">If set to <b><c>0</c></b>, the actor is returned to their old X coordinate once the animation is complete (for animations that move the actor such as walking). <b><c>1</c></b> will not return them to their old position</param>
/// <param name="locky">Same as above but for the Y axis. Should be kept the same as the previous parameter</param>
/// <param name="freeze">Setting this to <b><c>1</c></b> will freeze an actor at the end of the animation. <b><c>0</c></b> will not</param>
/// <param name="time">Timer in milliseconds. For a never-ending loop it should be <b><c>0</c></b></param>
/// <seealso name="ClearActorAnimations"/>
/// <remarks>You must preload the animation library for the player the actor will be applying the animation for, and not for the actor. Otherwise, the animation won't be applied to the actor until the function is executed again.</remarks>
/// <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
/// <returns>
/// <b><c>1</c></b>: The function executed successfully.<p/>
/// <b><c>0</c></b>: The function failed to execute. The actor specified does not exist.
/// </returns>
native ApplyActorAnimation(actorid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time);
native ClearActorAnimations(actorid);

native SetActorPos(actorid, Float:X, Float:Y, Float:Z);
native GetActorPos(actorid, &Float:X, &Float:Y, &Float:Z);
native SetActorFacingAngle(actorid, Float:ang);
native GetActorFacingAngle(actorid, &Float:ang);

native SetActorHealth(actorid, Float:health);
native GetActorHealth(actorid, &Float:health);
native SetActorInvulnerable(actorid, invulnerable = true);
native IsActorInvulnerable(actorid);

native IsValidActor(actorid);
