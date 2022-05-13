#include <ctest.h>
#include <stdio.h>

#include <libchessviz/chess.h>

#define FIRST_CELL board[first_crd]
#define SECOND_CELL board[second_crd]

CTEST(move, move_figure)
{
    table board;
    table_fill(board);
    int first_crd, second_crd;
    get_coordinates(&first_crd, &second_crd, "a2-a4");
    int needed_result = (int)FIRST_CELL.figure+FIRST_CELL.color*100; //100 to check color too actually
    move(board, "a2-a4");
    int actual_result = (int)SECOND_CELL.figure+SECOND_CELL.color*100; //again
    ASSERT_EQUAL(needed_result, actual_result);

    get_coordinates(&first_crd, &second_crd, "e7-e5");
    needed_result = (int)FIRST_CELL.figure+FIRST_CELL.color*100; //100 to check color too actually
    move(board, "e7-e5");
    actual_result = (int)SECOND_CELL.figure+SECOND_CELL.color*100; //again
    ASSERT_EQUAL(needed_result, actual_result);

    get_coordinates(&first_crd, &second_crd, "e2-e4");
    needed_result = (int)FIRST_CELL.figure+FIRST_CELL.color*100; //100 to check color too actually
    move(board, "e2-e4");
    actual_result = (int)SECOND_CELL.figure+SECOND_CELL.color*100; //again
    ASSERT_EQUAL(needed_result, actual_result);

    get_coordinates(&first_crd, &second_crd, "a7-a5");
    needed_result = (int)FIRST_CELL.figure+FIRST_CELL.color*100; //100 to check color too actually
    move(board, "a7-a5");
    actual_result = (int)SECOND_CELL.figure+SECOND_CELL.color*100; //again
    ASSERT_EQUAL(needed_result, actual_result);

    get_coordinates(&first_crd, &second_crd, "b2-b3");
    needed_result = (int)FIRST_CELL.figure+FIRST_CELL.color*100; //100 to check color too actually
    move(board, "b2-b3");
    actual_result = (int)SECOND_CELL.figure+SECOND_CELL.color*100; //again
    ASSERT_EQUAL(needed_result, actual_result);

    get_coordinates(&first_crd, &second_crd, "a8-a6");
    needed_result = (int)FIRST_CELL.figure+FIRST_CELL.color*100; //100 to check color too actually
    move(board, "a8-a6");
    actual_result = (int)SECOND_CELL.figure+SECOND_CELL.color*100; //again
    ASSERT_EQUAL(needed_result, actual_result);
}

CTEST(move, move_error)
{
    ASSERT_EQUAL(1, check_input("e2-e5"));
    ASSERT_EQUAL(1, check_input("e5-e6"));
    ASSERT_EQUAL(1, check_input("b2-b4"));
    ASSERT_EQUAL(1, check_input("c2-c6"));
    ASSERT_EQUAL(0, check_input("i2-e5"));
    ASSERT_EQUAL(0, check_input("dgfgr"));
    ASSERT_EQUAL(0, check_input("e8-e9"));
    ASSERT_EQUAL(0, check_input("e0-e1"));
    ASSERT_EQUAL(1, check_input("a1-h8"));
    ASSERT_EQUAL(1, check_input("c1-c8"));
    ASSERT_EQUAL(1, check_input("c2-c7"));
    ASSERT_EQUAL(1, check_input("h1-h7"));
    ASSERT_EQUAL(0, check_input("2d-4e"));
    ASSERT_EQUAL(0, check_input("0b-4a"));
    ASSERT_EQUAL(0, check_input("sd-a5"));
    ASSERT_EQUAL(0, check_input("j2-e5"));
}