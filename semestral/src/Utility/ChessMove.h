//
// Created by teodor on 10.06.22.
//

#pragma once

#include "coordinates.h"

/**
 * class representing any move in classical Chess
 * polymorphism delayed/dropped for simplification
 */
class ChessMove //: Move
{
    public:
        ChessMove() : dummy(true), valid(false), checkmate(false)
        {}

        void setValidMove(const coordinates & nStartPos, const coordinates & nEndPos, const int & nStatus)
        {
            movetype = nStatus;
            start = nStartPos;
            target = nEndPos;
        }
        void setEnPassant(const coordinates & nStartPos, const coordinates & nEndPos, const int & nStatus)
        {
            movetype = nStatus;
            start = nStartPos;
            target = nEndPos;
        }
        void setPromotion(const coordinates & nStartPos, const coordinates & nEndPos, const int & nStatus,
                const char & promoteTo)
        {
            movetype = nStatus;
            start = nStartPos;
            target = nEndPos;
            pieceId = promoteTo;
        }
        void setCastle(const coordinates & kingPos, const int & nStatus, const coordinates & buddy)
        {
            start = kingPos;
            target = buddy;
            movetype = nStatus;
        }
        void checkMate()
        { checkmate = true;}
        void setColour(const bool & nC)
        { movedBy = nC; }

        ChessMove validate()
        {
            valid = true;
            dummy = false;
            return *this;
        }
        ChessMove inValidate()
        {
            valid = false;
            dummy = false;
            return *this;
        }

        [[nodiscard]] bool isValid() const
        { return valid; }
        [[nodiscard]] bool isDummy() const
        { return dummy; }
        [[nodiscard]] bool isCheckMate() const
        { return checkmate; }
        [[nodiscard]] bool getColour() const
        { return movedBy; }
        [[nodiscard]] int moveType() const
        { return movetype; }
        [[nodiscard]] coordinates startPos() const
        { return start; }
        [[nodiscard]] coordinates endPos() const
        { return target; }
        [[nodiscard]] char promotionResult() const
        { return pieceId; }
    protected:
        bool dummy;
        bool valid;
        bool movedBy;
        bool checkmate;
        coordinates start;
        coordinates target;
        int movetype;
        // set by promotion move for target of promotion
        char pieceId;

};
