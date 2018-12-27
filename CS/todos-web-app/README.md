# Making a Simple "Todos" Web App using Elm

Welcome, all! This Lab will teach you how to make a simple *Todos* web application (similar to Apple Notes or Google Keep) using a programming language called *Elm*. Along the way, you'll learn a lot about programming, programming paradigms, (web) application design and development, and by the end you'll have a working prototype. These lessons will help you along in your EECS career!

> Wait, what is a web app?

A **web app** is just a computer application which users access through the web. For example: Gmail, Amazon, or Instagram. With web apps the user-interface (the web app's buttons and search bars) and client-side logic (the web app's behavior) is run on the user's browser. It is this, user-interface and client-side logic that we will be constructing today!

> Okay, what is Elm?

[Elm](https://elm-lang.org/) is a programming language like Python or Java, except it compiles to (or "turns into and runs as") JavaScript, so it can be run in the browser!

Elm is specifically designed to make user-interface centric applications, as such, using it in this lab will teach you many useful techniques programmers leverage when making large and complex software. Elm boasts excellent performance ([significantly better](https://elm-lang.org/blog/blazing-fast-html-round-two) than React) and perfect reliability (promising zero runtime errors). If those details don't mean anything to you, that's fine... just keep moving!

## Introduction to Elm

Now, for your information, Elm is a functional statically typed language. That means it is a bit different than other languages you may be familiar with. Never fear, just follow along! And, feel free to refer back to here if you need to while you are coding!

> Note: Many examples below are taken from [here](https://guide.elm-lang.org/core_language.html)

### Comments

Use `--` to create a comment. Comments are completely ignored when code is run, but they are useful as "notes to self".

```
-- I am a comment. I will be ignored by the computer.
```

### Values

Below are some Strings, representing snippets of text. Strings must be surrounded by quotation marks!

```
> "I am a string."
"I am a string."

> "This is how you combine " ++ "strings."
"This is how you combine strings."
```

Math works too.

```
> 2 + 3 * 4
14

> (2 + 3) * 4
20

> 9 / 2   -- "float" (similar to decimal) division
4.5

> 9 // 2  -- "integer" division
4
```

### Functions

Functions are simple yet powerful programming abstractions that let you model and modularize data flow... but, just think of them as little tools that do specific things. You can imagine, that if you have enough of these "little tools", you put many of them together to achieve more powerful things--that is why functions are great!

For now, lets make a simple function `isNeg` that takes in some number and tells you whether it is negative or not.

```
> isNeg x = x < 0
<function>
```

We can read the above code as: *Define a function called "isNeg" which takes in a number "x" and returns True if "x" is less than zero, otherwise the function returns False.*

Here is the function in action:

```
> isNeg 4
False

> isNeg -7
True
```

There are also *anonymous* functions or *unnamed* functions. Above, we created the function `isNeg` and gave it the name "isNeg". Let's make the same function again, but this time, without the name!

```
> \x -> x < 0
<function>
```

We can read the above code as: *Here is a unnamed function that takes in a number "x" and returns True if "x" is less than zero, otherwise the function returns False.*

### Conditionals

If you want conditional behavior, use if expressions, like so:

```
> perc = 85
> if perc >= 90 then "A" else if perc >= 80 then "B" else if perc >= 70 then "C" else if perc >= 60 then "D" else "F"
"B"
```

### Lists

You can also create lists!

```
> words = [ "hello", "bye", "3" ]
[ "hello", "bye", "3" ]

> nums = [ 1, 2, 3 ]
[ 1, 2, 3 ]
```

### Lastly, Records

A record is a set of **keys** and their associated **values**. You can use them like so:

```
> bill = { name = "Gates", age = 62 }
{ age = 62, name = "Gates" }
```

Here, `name` is a key with value `"Gates"`. And, `age` is a key too, with value `62`.

Do the following, to access the value of specific keys from within a record:

```
> bill.name
"Gates"
```

Records, as you might guess, can be extremely useful in representing the various details of real world objects, people, places, etc.

## Okay! Time to start coding!

Now, let's head over to our [Ellie editor](...) (Elm's quick and useful online coding playground). This is where you'll be doing your coding for this lab. There will be a lot of code that doesn't really make sense all over the place... Unfortunately, there is not enough time now to explain how everything works! We recommend you just edit the parts of code that this lab guides your through. Though, if you want to experiment, you can always click on the above link to "reset". At the end of the lab, we'll show you where to go learn more!

## Roadmap
- Step-by-step instructions and explanations of coding
- Step-by-step solution chunks
- Finished solution (Elm, working demo)
- Learn more
