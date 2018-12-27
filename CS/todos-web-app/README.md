# Making a Simple "Todos" Web App using Elm

Welcome! This lab will teach you how to make a simple "Todos" web application (similar to Apple Notes or Google Keep) using a programming language called *Elm*. It make get tough at times, so be sure to ask for help! Along the way, you'll learn a lot about programming, programming paradigms, (web) application design and development, and by the end you'll have a working prototype. These lessons will help you along in your EECS career!

> Wait, what is a web app?

A **web app** is just a computer application which users access through the web. For example: Gmail, Amazon, or Instagram. With web apps the user-interface (the web app's buttons and search bars) and client-side logic (the web app's behavior) is run on the user's browser. It is this user-interface and client-side logic, that we will be constructing today!

> Okay, what is Elm?

[Elm](https://elm-lang.org/) is a programming language like Python or Java, except it compiles to (or "turns into and runs as") JavaScript, so it can be run in the browser!

Elm is specifically designed for building user-interface centric applications, as such, using it in this lab will teach you many useful techniques programmers leverage when making large and complex software. Elm boasts excellent performance ([significantly better](https://elm-lang.org/blog/blazing-fast-html-round-two) than React) and perfect reliability (promising zero runtime errors). If those details don't mean anything to you, that's fine... just keep moving!

## Programming in Elm

Now, for your information, Elm is a functional statically typed language. That just means it is a bit different (better?) than other languages you may be familiar with. Never fear, just follow along! And, feel free to refer back to the followin section if you need to while you are coding!

> Note: Many examples below are taken from [here](https://guide.elm-lang.org/core_language.html).

### Comments

Use `--` to create a comment. Comments are completely ignored when code is run, but they are useful as "notes to self".

```elm
-- I am a comment. I will be ignored by the computer.
```

### Values

Below are some Strings, representing snippets of text. Strings must be surrounded by quotation marks!

```elm
> "I am a string."
"I am a string."

> "This is how you combine " ++ "strings."
"This is how you combine strings."
```

Math works too.

```elm
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

Functions are simple yet powerful programming abstractions that let you model and modularize data flow... but, just think of them as little tools that do specific things. You can imagine, that if you have enough of these "little tools", you can put many of them together to achieve more powerful things—that is why functions are great!

For now, lets make a simple function `isNeg` that takes in some number and tells you whether it is negative or not.

```elm
> isNeg x = x < 0
<function>
```

We can read the above code as: *Define a function called "isNeg" which takes in a number "x" and returns True if "x" is less than zero, otherwise the function returns False.*

Here is the function in action:

```elm
> isNeg 4
False

> isNeg -7
True
```

There are also *anonymous* functions or *unnamed* functions. Above, we created the function `isNeg` and gave it the name "isNeg". Let's make the same function again, but this time, without the name!

```elm
> \x -> x < 0
<function>
```

We can read the above code as: *Here is a unnamed function that takes in a number "x" and returns True if "x" is less than zero, otherwise the function returns False.*

### Conditionals

If you want conditional behavior, use if expressions, like so:

```elm
> perc = 85
> if perc >= 90 then "A" else if perc >= 80 then "B" else if perc >= 70 then "C" else if perc >= 60 then "D" else "F"
"B"
```

### Lists

You can also create lists!

```elm
> words = [ "hello", "bye", "3" ]
[ "hello", "bye", "3" ]

> nums = [ 1, 2, 3 ]
[ 1, 2, 3 ]
```

### Lastly, Records

A record is a set of **keys** and their associated **values**. You can create them like so:

```elm
> bill = { name = "Gates", age = 62 }
{ age = 62, name = "Gates" }
```

Here, `name` is a key with value `"Gates"`. And, `age` is a key too, with value `62`. Both are part of the same record, designated as `bill`.

Do the following, to access the value of specific keys from within a record:

```elm
> bill.name
"Gates"
```

We can also create new records from existing records, like so:

```elm
> youngBill = { bill | age = 24 }
{ age = 24, name = "Gates" }
```

Records, as you might guess, can be extremely useful in representing the various details of real world objects, people, places, etc.

## Okay! Time to start coding!

Now, let's head over to our [Ellie editor](https://ellie-app.com/4gX4GySfXZza1) (Elm's quick and useful online coding playground). This is where you'll be doing your coding for this lab. There will be a lot of code that doesn't really make sense all over the place... Unfortunately, there is not enough time now to explain how everything works! We recommend you just edit the parts of code that this lab guides your through. Though, if you want to experiment, there will be **code checkpoints** throughout the lab that contain all the "correct" code. You can use these to "reset" in case you think you messed up. At the end of the lab, we'll show you where to go learn more!

Elm Web Apps are built in **three parts**, together comprising the so-called *Elm Architecture*. It is a powerful way to capture and simplify the complexity of coding a web app. Getting experience with this approach to coding will surely help you as you engage in future programming endeavors.

### Part 1: The Model

> Note: The code we're starting out with WILL NOT COMPILE or FUNCTION until later parts.
>
> Note: You may ignore the code within the "HTML" section, for the purposes of this lab.

Let's start with the **model**. We want to define a data structure (like a list or a record) which can be used to represent the state of our web app. For example, when watching a YouTube video, the video can either be "Playing" or "Paused". This is the kind of state we wish to capture in our model. In our case we are trying to represent a todo list.

Let's start by writing the following, under the `-- MODEL` comment:

```elm
-- MODEL


type alias Item =
    { id : Int, content : String }
```

This `Item` **type** will be used to represent various **items** in the todo list of your "Todos" web app. Every `Item` must have an `id` number (for identification within our app) and some `content` which is the String that makes up the text of a given todo list item.

> Wait... what is a type?

Types organize data (such as our todo list items) in programs into well defined categories or types. Types have very specific rules defining how they flow through the program and how they interact with other types. Here are some types you might know: `Int` for numbers like `1`, `2`, and `3`; `String` for representing text such as `"Hello, world!"`; or, `Bool` for the values `True` and `False`. Notice that `Int` + `Int` makes sense... But `Bool` + `String` does not. Types ensure our code makes sense and actually works!

Likewise, we define the `Model` type as follows:

```elm
type alias Model =
    { newItemContent : String
    , items : List Item
    }
```

Here, `items` is a `List` of `Item`s. This list will be used to hold all the todo items that our web app cares about.

The `newItemContent` is the String of text that will be used when adding a new todo list `Item` to our list of todo items.

Lastly, we must **initialize** our model:

```elm
init =
    Model "" []
```

Your code should look like this now:

**-- Code Checkpoint #1 --**

```elm
module Main exposing (main)

import Browser
import Html exposing (Html, button, div, h1, input, li, span, text, ul)
import Html.Attributes exposing (placeholder, value)
import Html.Events exposing (onClick, onInput)


main =
    Browser.sandbox
        { init = init
        , view = view
        , update = update
        }



-- MODEL


type alias Item =
    { id : Int, content : String }


type alias Model =
    { newItemContent : String
    , items : List Item
    }


init =
    Model "" []



-- UPDATE
-- VIEW
```

### Part 2: The Update Function

In the **update** part we do two things.

First, we define a `Msg` (or message) type. This will be used to define all possible reasons for the state of our app (or the **model**) to change. For example, if a user of our web app clicks an "add new item" button, that would cause a new item to be added to our app, thus, our app's state must change.

Here is the type definition for `Msg`:

```elm
type Msg
    = EditNewItem String
    | AddNewItem String
    | EditItem Item String
    | DeleteItem Item
```

So, our app can receive the above defined "messages", such as, `AddNewItem String` which means: *Add a new item with this String as the text content for that item.*

Secondly, we will work on our **update** function.

Below, is an incomplete update function. You must fill in the `???`s under the `AddNewItem` branch to get the update function working.

```elm
update msg model =
    case msg of
        EditNewItem newContent ->
            { model | newItemContent = newContent }

        AddNewItem newContent ->
            { model
                | ??? =
                    model.items ++ [ Item (List.length model.items) ??? ]
                , newItemContent = ""
            }

        EditItem item newContent ->
            { model
                | items =
                    List.map
                        (\x ->
                            if x == item then
                                { x | content = newContent }

                            else
                                x
                        )
                        model.items
            }

        DeleteItem item ->
            { model | items = List.filter (\x -> x /= item) model.items }
```

The `update` function takes in `msg`s (a.k.a. messages) and the current state of the app (a.k.a. the `model`). Based on what the `msg` is, the update function will have a different behavior—a behavior for each possible kind of `msg` (we defined these in the previous code block). Thus, the `update` function is able to return a **new model** with the necessary changes to the state of the app, appropriate to the given `msg`. For example, if the update function is given a `msg` of `DeleteItem`, the update function will return a new model with a specific item removed from the `items` of the model.

So, for the `AddNewItem` branch, we want to produce a new model from the old one, such that, the new model's list of todo items called `items` includes a brand new item with the String `newContent` as this brand new item's text content.

The correct solution is this:

```elm
    AddNewItem newContent ->
            { model
                | items =
                    model.items ++ [ Item (List.length model.items) newContent ]
                , newItemContent = ""
            }
```

**-- Code Checkpoint #2 --**

```elm
module Main exposing (main)

import Browser
import Html exposing (Html, button, div, h1, input, li, span, text, ul)
import Html.Attributes exposing (placeholder, value)
import Html.Events exposing (onClick, onInput)


main =
    Browser.sandbox
        { init = init
        , view = view
        , update = update
        }



-- MODEL


type alias Item =
    { id : Int, content : String }


type alias Model =
    { newItemContent : String
    , items : List Item
    }


init =
    Model "" []



-- UPDATE


type Msg
    = EditNewItem String
    | AddNewItem String
    | EditItem Item String
    | DeleteItem Item


update msg model =
    case msg of
        EditNewItem newContent ->
            { model | newItemContent = newContent }

        AddNewItem newContent ->
            { model
                | items =
                    model.items ++ [ Item (List.length model.items) newContent ]
                , newItemContent = ""
            }

        EditItem item newContent ->
            { model
                | items =
                    List.map
                        (\x ->
                            if x == item then
                                { x | content = newContent }

                            else
                                x
                        )
                        model.items
            }

        DeleteItem item ->
            { model | items = List.filter (\x -> x /= item) model.items }



-- VIEW
```

### Part 3: The View

So, we have a way to *model* our app and *update* that model... But now, we will finally learn how to **view** our Todos web app!

The `view` function takes in a `model` and turns it into HTML code that the browser can display to the user! We don't have the time to teach HTML right now, but check out the following code block and add it to your program!

```elm
-- VIEW


view model =
    div []
        [ h1 [] [ text "Todos" ]
        , ul []
            (listItems model.items
                ++ [ li []
                        [ button
                            [ onClick (AddNewItem model.newItemContent) ]
                            [ text "＋" ]
                        , input [ placeholder "Add todo...", onInput EditNewItem, value model.newItemContent ] []
                        ]
                   ]
            )
        ]


listItems items =
    List.map (\x -> li [] [ button [ onClick (DeleteItem x) ] [ text "✔" ], input [ onInput (EditItem x), value x.content ] [] ]) items

```

As you can see, the view function turns a `model` into an a bunch of HTML elements (`h1`, `ul`, `li`, etc) all wrapped in a `div` element.

> Fun fact: These HTML elements here, are actually just functions that return HTML types!

What's really interesting is that the HTML can produce `Msg`s! Look at these lines in particular:

```elm
                        [ button
                            [ onClick (AddNewItem model.newItemContent) ]
```

This means that when a user **clicks** on the HTML button element produced by the view function and shown in the web browser, it will produce an `AddNewItem` message of type `Msg`! This `AddNewItem` message will be fed into our `update` function... this is how our update function actually recieves `msg`s, and how the web app keeps driving forward!

Now all you must do is click on the **COMPILE** button on the top of the editor and try out your brand new Todos web app! Does everything work!?

> If you did get an error, read it carefuly and try to fix things! Then hit **COMPILE** again!

## That's a wrap!

Below, is the finished code! And [here](https://ellie-app.com/4gWNjVCN76ga1) is a functioning demo, just in case! Well done!

**-- Code Checkpoint #3 --**

```elm
module Main exposing (main)

import Browser
import Html exposing (Html, button, div, h1, input, li, span, text, ul)
import Html.Attributes exposing (placeholder, value)
import Html.Events exposing (onClick, onInput)


main =
    Browser.sandbox
        { init = init
        , view = view
        , update = update
        }



-- MODEL


type alias Item =
    { id : Int, content : String }


type alias Model =
    { newItemContent : String
    , items : List Item
    }


init =
    Model "" []



-- UPDATE


type Msg
    = EditNewItem String
    | AddNewItem String
    | EditItem Item String
    | DeleteItem Item


update msg model =
    case msg of
        EditNewItem newContent ->
            { model | newItemContent = newContent }

        AddNewItem newContent ->
            { model
                | items =
                    model.items ++ [ Item (List.length model.items) newContent ]
                , newItemContent = ""
            }

        EditItem item newContent ->
            { model
                | items =
                    List.map
                        (\x ->
                            if x == item then
                                { x | content = newContent }

                            else
                                x
                        )
                        model.items
            }

        DeleteItem item ->
            { model | items = List.filter (\x -> x /= item) model.items }



-- VIEW


view model =
    div []
        [ h1 [] [ text "Todos" ]
        , ul []
            (listItems model.items
                ++ [ li []
                        [ button
                            [ onClick (AddNewItem model.newItemContent) ]
                            [ text "＋" ]
                        , input [ placeholder "Add todo...", onInput EditNewItem, value model.newItemContent ] []
                        ]
                   ]
            )
        ]


listItems items =
    List.map (\x -> li [] [ button [ onClick (DeleteItem x) ] [ text "✔" ], input [ onInput (EditItem x), value x.content ] [] ]) items
```

## Want to learn more?

- Check out the official Elm guide [here](https://guide.elm-lang.org)
- Learn more about Elm in general [here](https://elm-lang.org)
- Learn how to style our app with your own [CSS](https://www.w3schools.com/css)
- Learn [HTML](https://www.w3schools.com/html/default.asp) and how it makes the web work
- Challenge: try to make your Todos app able to add `Item`s by pressing the ENTER key on the keyboard instead of only being able to do so by pressing the **+** button.
- Challenge: there is actually a small bug in this web app... can you find it and squash it?
- Challenge: make your own Elm app! Get creative!
