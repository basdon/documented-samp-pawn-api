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


/// <summary>Get the length of a string.</summary>
/// <param name="string">The string to get the length of</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <returns>The length of the string as an integer.</returns>
native strlen(const string[]);

/// <summary>Pack a string. Packed strings use 75% less memory.</summary>
/// <param name="dest">The destination string to save the packed string in, passed by reference</param>
/// <param name="source">The source, original string</param>
/// <param name="maxlength">The maximum size to insert (optional=<b><c>sizeof dest</c></b>)</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <returns>The number of characters packed.</returns>
native strpack(dest[], const source[], maxlength=sizeof dest);

/// <summary>This function can be used to unpack a string.</summary>
/// <param name="dest">The destination string to save the unpacked string in, passed by reference</param>
/// <param name="source">The source, original packed string</param>
/// <param name="maxlength">The maximum size to insert (optional=<b><c>sizeof dest</c></b>)</param>
/// <seealso name="ispacked"/>
/// <seealso name="strpack"/>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <returns>The number of characters packed.</returns>
native strunpack(dest[], const source[], maxlength=sizeof dest);

/// <summary>This function concatenates (joins together) two strings into the destination string.</summary>
/// <param name="dest">The string to store the two concatenated strings in</param>
/// <param name="source">The source string</param>
/// <param name="maxlength">The maximum length of the destination (optional=<b><c>sizeof dest</c></b>)</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <returns>The length of the new destination string.</returns>
native strcat(dest[], const source[], maxlength=sizeof dest);


/// <summary>Extract a range of characters from a string.</summary>
/// <param name="dest">The string to store the extracted characters in</param>
/// <param name="source">The string from which to extract characters</param>
/// <param name="start">The position of the first character</param>
/// <param name="end">The position of the last character</param>
/// <param name="maxlength">The length of the destination. (optional=<b><c>sizeof dest</c></b>)</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <returns>The number of characters stored in dest[].</returns>
native strmid(dest[], const source[], start, end, maxlength=sizeof dest);

/// <summary>Insert a string into another string.</summary>
/// <param name="string">The string you want to insert substr in</param>
/// <param name="substr">The string you want to insert into string</param>
/// <param name="pos">The position to start inserting</param>
/// <param name="maxlength">The maximum size to insert (optional=<b><c>sizeof string</c></b>)</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
native bool: strins(string[], const substr[], pos, maxlength=sizeof string);

/// <summary>Delete part of a string.</summary>
/// <param name="string">The string to delete part of</param>
/// <param name="start">The position of the first character to delete</param>
/// <param name="end">The position of the last character to delete</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
native bool: strdel(string[], start, end);


/// <summary>Compares two strings to see if they are the same.</summary>
/// <param name="string1">The first string to compare</param>
/// <param name="string2">The second string to compare</param>
/// <param name="ignorecase">When set to true, the case doesn't matter - HeLLo is the same as Hello. When false, they're not the same (optional=<b><c>0</c></b>)</param>
/// <param name="length">When this length is set, the first x chars will be compared - doing "Hello" and "Hell No" with a length of 4 will say it's the same string (optional=<b><c>cellmax</c></b>)</param>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <remarks>This function returns <b><c>0</c></b> if either string is empty. Check for null strings with <c>isnull()</c>. If you do not, for example, people can login to anyone's account by simply entering a blank password. </remarks>
/// <remarks>
///   <code>
///   #if !defined isnull<p/>
///   &#9;#define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') &amp;&amp; (!(%1[1]))))<p/>
///   #endif
///   </code>
/// </remarks>
/// <remarks>If you compare strings from a text file, you should take in to account the 'carriage return' and 'new line' special characters (\r \n), as they are included, when using fread.</remarks>
/// <returns>
///   <b><c>0</c></b> if strings match each other on given length;.<p/>
///   <b><c>1</c></b> or <b><c>-1</c></b> if some character do not match: <c>string1[i] - string2[i]</c>.<p/>
///   <b>difference in number of characters</b> if one string matches only part of another string.
/// </returns>
native strcmp(const string1[], const string2[], bool:ignorecase=false, length=cellmax);

/// <summary>Search for a sub string in a string.</summary>
/// <param name="string">The string you want to search in (haystack)</param>
/// <param name="sub">The string you want to search for (needle)</param>
/// <param name="ignorecase">When set to true, the case doesn't matter - HeLLo is the same as Hello. When false, they're not the same (optional=<b><c>0</c></b>)</param>
/// <param name="pos">The offset to start searching from (optional=<b><c>0</c></b>)</param>
/// <seealso name="strcmp"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strval"/>
/// <seealso name="strcat"/>
/// <returns>The number of characters before the sub string (the sub string's start position) or <b><c>-1</c></b> if it's not found.</returns>
native strfind(const string[], const sub[], bool:ignorecase=false, pos=0);


/// <summary>Convert a string to an integer.</summary>
/// <param name="const string">The string you want to convert to an integer</param>
/// <seealso name="strcmp"/>
/// <seealso name="strfind"/>
/// <seealso name="strtok"/>
/// <seealso name="strdel"/>
/// <seealso name="strins"/>
/// <seealso name="strlen"/>
/// <seealso name="strmid"/>
/// <seealso name="strpack"/>
/// <seealso name="strcat"/>
/// <returns>The integer value of the string. <b><c>0</c></b> if the string is not numeric.</returns>
native strval(const string[]);
native valstr(dest[], value, bool:pack=false);

/// <summary>Checks if the given string is packed.</summary>
/// <param name="string">The string to check</param>
/// <returns><b><c>1</c></b> if the string is packed, <b><c>0</c></b> if it's unpacked.</returns>
native bool: ispacked(const string[]);


/// <summary>Decode an UU-encoded string.</summary>
/// <param name="dest">The destination for the decoded string array</param>
/// <param name="source">The UU-encoded source string</param>
/// <param name="maxlength">The maximum length of dest that can be used (optional=<b><c>sizeof dest</c></b>)</param>
native uudecode(dest[], const source[], maxlength=sizeof dest);
native uuencode(dest[], const source[], numbytes, maxlength=sizeof dest);

/// <summary>Copy bytes from one location to another.</summary>
/// <param name="dest">An array into which the bytes from source are copied in</param>
/// <param name="source">The source array</param>
/// <param name="index">The start index in bytes in the destination array where the data should be copied to (optional=<b><c>0</c></b>)</param>
/// <param name="numbytes">The number of bytes (not cells) to copy</param>
/// <param name="maxlength">The maximum number of cells that fit in the destination buffer (optional=<b><c>sizeof dest</c></b>)</param>
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
