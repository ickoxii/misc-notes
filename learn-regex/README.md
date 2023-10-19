# RegexOne

These notes have been taken from [https://regexone.com](https://regexone.com).

## Lesson 1: An Introduction, and the ABC's

Regular expressions are extremely useful in extracting information from text.
The first thing to recognize is that **everything is a character**.

regex allows you to match characters anywhere in the string.

> regex: abc  
> **abc**def  
> **abc**de  
> **abc**d  
> **abc**  
  
> regex: 123  
> abc**123**xyz  
> define "**123**"  
> var g = **123**;  

## Lesson 2: The Dot

The dot operator `.` is a wildcard and can match any ***single*** character. 
In order to match an actual period character, we need to escape the operator 
by using a slash, ie. `\.`. The following shows a way to match the first three 
strings but now the last.

> regex: ...\.  
> match: **cat**.  
> match: **?=+**.  
> match: **896**.  
> skip:  abc1  

## Lesson 3: Matching Specific Characters

Sometimes `.` is too powerful for our use. For example, if we wanted to 
validate a phone number but we used `.`, it would allow *(abc) def-ghif* 
as being a valid phone number!  

In order to match specific characters, we define then inside square brackets. 
For example, the patter `[abc]` will only match a **single** 'a', 'b', or 'c' 
letter and nothing else.  

Below are a few lines, match only the first three strings using regex, but not 
the last three.

> regex: [cmf]an  
> match: **can**  
> match: **man**  
> match: **fan**  
> skip:  dan  
> skip:  ran  
> skip:  pan  

## Lesson 4: Excluding Specific Characters

In other cases, we might want to exclude specific characters instead of 
including them. To represent this, we use the hat operator `^`. For example, 
the pattern `[^abc]` will match any **single** character ***except for*** 
the letters 'a', 'b', or 'c'.  

Match the lines that match with hog and dog, but not bog

> regex: [\^b]og  
> match: **hog**  
> match: **dog**  
> skip:  bog  

## Lesson 5: Character Ranges

Use a dash to indicate a character range of sequential characters to match. 
For example, the pattern `[0-6]` will match a single digit from 0 to 6, and 
the pattern `[^n-p]` will match a single character **except** for the letters 
from n through p.  

Multiple character ranges can be used in the same set of brackets, along with 
individual characters. An example of this is the alphanumberic `\w` 
metacharacter which is equivalent to the character range `[A-Za-z0-9_]` and 
is often used to match characters in English text.

## Lesson 6: Repititions of Characters to Match

Say we want to match a string of 'z's. Instead of specifying "we want a string 
with three z's" using the regex `[zzz]`, we could instead specify the amount 
of repititions inside curly braces ('{}'). 

For example, `a{3}` will match the 'a' character exactly three times. We can 
also specify ranges, depending on our regex engine. `a{1, 3}` will match 
string that contain a sequence of 'a' characters of length 1 to 3, no more 
than 3, no less than 1.  

In addition, depending on the regex engine, we can leave the ranges blank 
to allow 'infinite' bounds (i.e. `{,5}`, `{3,}`).  

These curly braces can also be used with our special metacharacters (i.e. the 
character ranges from previous lessons).

|Regex|         Explanation             |
|:---:|:-------------------------------:|
|[xy]{5}|5 characters, either x or y    |
|.{2-6}|between 2 and 6 characters      |

## Lesson 7: The Kleene Star and Kleene Plus

The Kleene operators allow us to match an arbitraty number of characters. 
The **Kleene Star** represents 0 or more of the character it follows, and the 
**Klene Plus** represents 1 or more of the character it follows.  

> `a+` - one or more a's   
> `[abc]+` - one or more of any 'a', 'b', or 'c' character  
> `.*` - zero or more of any character  

## Lesson 8: Optional Characters

The Kleene star and plus allow us to match repeated characters in a line. 
Another quantifier is the `?` metacharacter which denotes **optionality**. 
The `?` allows us to match either zero or one or the preceding character or 
group. For example, the regex pattern "ab?c" will match both "abc" and "ac" 
because the 'b' character is considered optional.  

To match a '?' in the text, escape the optionality metacharacter using a 
backslash, i.e. '\?'.

### Example

Try writing a pattern that uses the optionality metacharacter to match 
only the lines where one or more files were found.

> regex: `[0-9]* files? found\?`  
> match: **1 file found?**  
> match: **24 files found?**  
> match: **2 files found?**  
> skip:  No files found.

## Lesson 9: Whitespace

The most common forms of whitespace are the space (`_`), the tab(`\t`), the 
new line (`\n`), and the carriage return (`\r`). In addition, a whitespace 
special character `\s` will match any of the whitespaces above and is 
extremely useful when dealing with raw input text. 


### Example

Try writing a pattern that will match the lines that contain whitespace.  

> regex: `\d\.\s+abc`  
> match: **1.   abc**
> match: **2.       abc**  
> match: **3.        abc**  
> skip:  4.abc  

## Lesson 10: Starting and Ending
