1. Valid Parenthesis => {
    eg : ([]{[()]}())

    - push bracket to a stack : & for every closing bracket : check if there is 
    an opening bracket or not : yes => pop out the op bracket from stack 
    - at end of str : stack empty : then valid else not valid
}