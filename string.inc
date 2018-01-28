/* String functions
 *
 * (c) Copyright 2005, ITB CompuPhase
 * This file is provided as is (no warranties).
 */
#if defined _string_included
  #endinput
#endif
#define _string_included
#pragma library String

native strlen(const string[]);
native strpack(dest[], const source[], maxlength=sizeof dest);
native strunpack(dest[], const source[], maxlength=sizeof dest);
native strcat(dest[], const source[], maxlength=sizeof dest);

native strmid(dest[], const source[], start, end, maxlength=sizeof dest);
native bool: strins(string[], const substr[], pos, maxlength=sizeof string);
native bool: strdel(string[], start, end);

native strcmp(const string1[], const string2[], bool:ignorecase=false, length=cellmax);
native strfind(const string[], const sub[], bool:ignorecase=false, pos=0);

native strval(const string[]);
native valstr(dest[], value, bool:pack=false);

/// <summary>Checks if the given string is packed.</summary>
/// <param name="string">The string to check</param>
/// <returns><b><c>1</c></b> if the string is packed, <b><c>0</c></b> if it's unpacked.</returns>
native bool: ispacked(const string[]);

native uudecode(dest[], const source[], maxlength=sizeof dest);
native uuencode(dest[], const source[], numbytes, maxlength=sizeof dest);

/// <summary>Copy bytes from one location to another.</summary>
/// <param name="dest">An array into which the bytes from source are copied in</param>
/// <param name="source">The source array</param>
/// <param name="index">The start index in bytes in the destination array where the data should be copied to (optional=<b><c>0</c></b>)</param>
/// <param name="numbytes">The number of bytes (not cells) to copy</param>
/// <param name="maxlength">The maximum number of cells that fit in the destination buffer (optional=<b><c>sizeof dest</c></b>)</param>
/// <seealso name=""/>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
native memcpy(dest[], const source[], index=0, numbytes, maxlength=sizeof dest);
