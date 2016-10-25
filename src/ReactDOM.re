external render : React.reactElement => Document.element => unit = "" [@@bs.val] [@@bs.module
                                                                    "react-dom"
                                                                    ];

external unmountComponentAtNode : Document.element => unit = "" [@@bs.val] [@@bs.module
                                                                    "react-dom"
                                                                    ];
