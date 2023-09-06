All information is taken from <www.markdownguide.org>

# Learning Markdown text (.md files)

## Headings

# Heading level 1 (largest)

or,

Heading level 1
===============

## Heading level 2

or,

Heading level 2
---------------

### Heading level 3

#### Heading level 4

##### Heading level 5

###### Heading level 6 (smallest)

## Line Breaks

Use a blank line to separate one or more lines

of text like this.

Create a line break by ending a line with two or more spaces 
and typing return.    
Here is the second line.

## Emphasis

### Bullet points

- easy
- clap
- baby

### Bold

Add two asterisks (or underscores) before and after a word or phrase.
To bold the middle of a word for emphasis, add two asterisks without
spaces around the letters.

I just love **bold text**
Sti**ck**yI**ck**y

### Italics

Add one asterisk (or underscore) before and after a word or phrase.
To italicize the middle of a word for emphasis, add one asterisk
without spaces aroud the letters.

*StickyIcky*
I like *italics* sometimes.

### Bold and Italics (at the same time)

Use a combination of three asterisks (or underscores) before and after
a word or phrase. But realistically, don't be dumb, just use asterisks.
To bold and italicize the middle of a word blah blah see above

This text is ***really important***.
This test is only ha***lfw***ay imp***ort***ant.

### Blockquotes

To create a blockquote, add a '>' in front of a paragraph. This will
create a separate block of text for the resulting paragraph.

> This is a block-quote
> 
> Note that we continue the '>' on the blank line to have multiple
> paragraphs within the block-quote.

#### Nested block-quotes

> Block quote 1
>
>> Block quote 2
>>
>>> Block quote 3???


#### Block-quotes with other markdown elements

Blockquotes can contain other Markdown formatted elements. Not all
elements can be used -- good luck experimenting lmao.

> #### Heading level!!!
>
> - bullet
> - points
> - brother
>
>> *Italicize* **my** ***asshole***

## Lists

Lists can either be ordered or unordered.

### Ordered Lists

To create an ordered list, add numbers followed by a period.
The numbers don't have to be in numberical order, but the list
should start with the number one. All the following will print
an ordered list from 1 to 4.

1. first
2. second
3. third
4. fourth

1. first
1. second
1. third
1. fourth

1. first
8. second
3. third
5. fourth

1. first
    1. first indented
    2. second indented
2. second
3. third
    1. first indented
    2. second indented
4. fourth

### Unordered Lists (bullet points)

To create an unordered list, use '-', '\*', or '+'. Indent
one or more items to create a nested list.

- first
- second
- third
- fourth

* first
* second
* third
* fourth

+ first
+ second
+ third
+ fourth

#### Started Unordered Lists With Numbers

If you need to start an unordered list item with a number
followed by a period, you can use a backslash '\' to escape
the period.

- 1969\. nice...

## Code

To denote a word or phrase as code, enclose it in backticks (\`).

At the command prompt, type `vim`.

### Escaping backticks

If the word or phrase you want to denote as code includes one or
more backticks, you can escape it by enclosing the word or phrase
in double backticks (\`\`).

This will print the backticks surrounding 'code'.

``Use `code` in your Markdown file.``

### Code Blocks

To create code blocks, indent every line of the block by at least
four spaces or one tab.

`
int main() {
    std::cout << "Hello world" << std::endl;
    return 0;
}
`

## Horizontal Rules

To create a horizontal rule, use three or more asterisks, dashes,
or underscores on a line by themselves.

***

---

___

## Links

To create a link, enclose the link text in brackets \[link-text\]
and then follow it immediately with the URL in parenthesis.

[My GitHub](https://github.com/ickoxii)

### Adding Titles

You can optionally add a title for a link. This will appear as a
tooltip when the user hovers over the link. To add a title, enclose
it in quotation marks after the URL.

[My GitHub](https://github.com/ickoxii "I dont know what I'm doing")

### URLs and Email Addresses

To quickly turn a URL or email address into a link, enclose it
in angle brackets.

<https://github.com/ickoxii>
<no-reply@github.com>

### Formatting Links

To emphasize links, add asterisks before and after the brackets and
parenthesis. To denote links as code, add backticks in the brackets.

Here is bold **[GitHub](https://github.com)**
Here is italic *[GitHub](https://github.com)*
See the section on [`code`](#code).

### Reference-style Links

Reference-style links are a special kind of link that make URLs
easier to display and read in Markdown. Reference-style links are
constructed in two parts: the part you keep inline with your text
and the part where you store somewhere else in the file to keep the
text easy to read.

#### Formatting the First Part of the Link

The first part of the link is setting up the text that will actually
appear, and linking this to a reference label.

The first set of brackets contains the set of text to appear.
The second set of brackets is case in-sensitive and can include
letters, numbers, spaces, or punctuation.

For \[GitHub\]\[1\]:

- GitHub: text that appears.
- 1: our reference label.

[GitHub][1]

#### Formatting the Second Part of the Link

The second part of the link is where we setup where this link
will redirect the user to. This section can be placed anywhere
within the Markdown document. People will typically place their
reference links either after the paragraph or at the very
end of the file.

There are three attributes to the second part of reference-style
links.

1. The label, in brackets, followed immediately by a colon
and at least one space
2. The URL for the link, which can optionally be enclosed
in angle brackets.
3. The optional title for the link, which can be enclosed
in double quotes, single quotes, or parentheses.

The following formats are all equivalent:

[1]: https://github.com
[1]: https://github.com "title"
[1]: https://github.com 'title'
[1]: https://github.com (title)
[1]: <https://github.com>
[1]: <https://github.com> "title"
[1]: <https://github.com> 'title'
[1]: <https://github.com> (title)

### Handling Spaces

Markdown applications don't agree on how to handle spaces in the
middle of a URL. For compatibility, try to URL encode any spaces
with `%20`. Alternatively, if your Markdown application supports
HRML, you could use the `a` HTML tag.

> Do this:
> [link] (https://example.com/my%20great%20page)

## Images

To add an image, add an exclamation mark followed by alt text
in the brackets, and the path or URL to the image asset in
parentheses. You can optionally add a title in quotations
after the path or URL.

`![The San Juan Mountains are beautiful!](/assets/images/picture.jpg "San Juan Mountains")`

## Escaping Characters

To display a literal character that would otherwise be used
to format text in a Markdown document, add a backslash in front
of the character

> Characters you can escape:
>
> \\    backslash
> \`    backtick
> \*    asterisk
> \_    underscore
> \{\}  curly braces
> \[\]  brackets
> \<\>  angle brackets
> \(\)  parentheses
> \#    pound sign
> \+    plus sign
> \-    minus sign
> \.    dot
> \!    exclamation mark
> \|    pipe

