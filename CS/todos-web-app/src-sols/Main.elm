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
