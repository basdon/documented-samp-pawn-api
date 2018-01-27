/* Core functions
 *
 * (c) Copyright 1998-2005, ITB CompuPhase
 * This file is provided as is (no warranties).
 */
#if defined _core_included
  #endinput
#endif
#define _core_included
#pragma library Core

native heapspace();

native funcidx(const name[]);

native numargs();
native getarg(arg, index=0);
native setarg(arg, index=0, value);

native tolower(c);
native toupper(c);
native swapchars(c);

native random(max);

native min(value1, value2);
native max(value1, value2);

/// <summary>Force a value to be inside a range.</summary>
/// <param name="value">The value to force in a range</param>
/// <param name="min">The low bound of the range (optional=<b><c>cellmin</c></b>)</param>
/// <param name="max">The high bound of the range (optional=<b><c>cellmax</c></b>)</param>
/// <returns>value, if it is in the range min–max, min, if value is lower than min or max, if value is higher than max.</returns>
native clamp(value, min=cellmin, max=cellmax);

native getproperty(id=0, const name[]="", value=cellmin, string[]="");
native setproperty(id=0, const name[]="", value=cellmin, const string[]="");

/// <summary>Delete an earlier set property (<a href="#setproperty">setproperty</a>).</summary>
/// <param name="id">The <a href="http://en.wikipedia.org/wiki/Virtual_machine">virtual machine</a> to use. You should keep this as zero (optional=<b><c>0</c></b>)</param>
/// <param name="name">The property's name, you should keep this blank (optional=<b><c>""</c></b>)</param>
/// <param name="value">The property's unique ID. Use the hash-function to calculate it from a string (optional=<b><c>cellmin</c></b>)</param>
/// <seealso name="Setproperty"/>
/// <seealso name="Getproperty"/>
/// <seealso name="Existproperty"/>
/// <returns>The value of the property. If the property does not exist, the function returns <b><c>0</c></b>.</returns>
native deleteproperty(id=0, const name[]="", value=cellmin);

/// <summary>Check if a property exist.</summary>
/// <param name="id">The <a href="http://en.wikipedia.org/wiki/Virtual_machine">virtual machine</a> to use, you should keep this zero (optional=<b><c>0</c></b>)</param>
/// <param name="name">The property's name, you should keep this (optional=<b><c>""</c></b>)</param>
/// <param name="value">The property's unique ID. Use the hash-function to calculate it from a string (optional=<b><c>cellmin</c></b>)</param>
/// <seealso name="Setproperty"/>
/// <seealso name="Getproperty"/>
/// <seealso name="Deleteproperty"/>
/// <returns><b><c>True</c></b> if the property exists and <b><c>false</c></b> otherwise.</returns>
native existproperty(id=0, const name[]="", value=cellmin);

