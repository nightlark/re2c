# Generated by re2c
# re2py $INPUT -o $OUTPUT

from enum import Enum

class Num(Enum):
    INT = 1
    FLOAT = 2
    NAN = 3




def lex(yyinput):
    yycursor = 0
    
    yyaccept = 0
    yystate = 0
    while True:
        match yystate:
            case 0:
                yych = yyinput[yycursor]
                yycursor += 1
                if yych <= 0x2F:
                    if yych == 0x2E:
                        yystate = 2
                        continue
                else:
                    if yych <= 0x30:
                        yystate = 3
                        continue
                    if yych <= 0x39:
                        yystate = 4
                        continue
                yystate = 1
                continue
            case 1:
                return Num.NAN
            case 2:
                yych = yyinput[yycursor]
                if yych <= 0x2F:
                    yystate = 1
                    continue
                if yych <= 0x39:
                    yycursor += 1
                    yystate = 6
                    continue
                yystate = 1
                continue
            case 3:
                yyaccept = 0
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych <= 0x39:
                    if yych == 0x2E:
                        yycursor += 1
                        yystate = 6
                        continue
                    if yych <= 0x2F:
                        yystate = 1
                        continue
                    yycursor += 1
                    yystate = 8
                    continue
                else:
                    if yych <= 0x45:
                        if yych <= 0x44:
                            yystate = 1
                            continue
                        yycursor += 1
                        yystate = 10
                        continue
                    else:
                        if yych == 0x65:
                            yycursor += 1
                            yystate = 10
                            continue
                        yystate = 1
                        continue
            case 4:
                yyaccept = 1
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych <= 0x39:
                    if yych == 0x2E:
                        yycursor += 1
                        yystate = 6
                        continue
                    if yych >= 0x30:
                        yycursor += 1
                        yystate = 4
                        continue
                    yystate = 5
                    continue
                else:
                    if yych <= 0x45:
                        if yych >= 0x45:
                            yycursor += 1
                            yystate = 10
                            continue
                        yystate = 5
                        continue
                    else:
                        if yych == 0x65:
                            yycursor += 1
                            yystate = 10
                            continue
                        yystate = 5
                        continue
            case 5:
                return Num.INT
            case 6:
                yyaccept = 2
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych <= 0x44:
                    if yych <= 0x2F:
                        yystate = 7
                        continue
                    if yych <= 0x39:
                        yycursor += 1
                        yystate = 6
                        continue
                    yystate = 7
                    continue
                else:
                    if yych <= 0x45:
                        yycursor += 1
                        yystate = 10
                        continue
                    if yych == 0x65:
                        yycursor += 1
                        yystate = 10
                        continue
                    yystate = 7
                    continue
            case 7:
                return Num.FLOAT
            case 8:
                yych = yyinput[yycursor]
                if yych <= 0x39:
                    if yych == 0x2E:
                        yycursor += 1
                        yystate = 6
                        continue
                    if yych >= 0x30:
                        yycursor += 1
                        yystate = 8
                        continue
                    yystate = 9
                    continue
                else:
                    if yych <= 0x45:
                        if yych >= 0x45:
                            yycursor += 1
                            yystate = 10
                            continue
                        yystate = 9
                        continue
                    else:
                        if yych == 0x65:
                            yycursor += 1
                            yystate = 10
                            continue
                        yystate = 9
                        continue
            case 9:
                yycursor = yymarker
                if yyaccept <= 1:
                    if yyaccept == 0:
                        yystate = 1
                        continue
                    else:
                        yystate = 5
                        continue
                else:
                    yystate = 7
                    continue
            case 10:
                yych = yyinput[yycursor]
                if yych <= 0x2C:
                    if yych != 0x2B:
                        yystate = 9
                        continue
                    yycursor += 1
                    yystate = 11
                    continue
                else:
                    if yych <= 0x2D:
                        yycursor += 1
                        yystate = 11
                        continue
                    if yych <= 0x2F:
                        yystate = 9
                        continue
                    if yych <= 0x39:
                        yycursor += 1
                        yystate = 12
                        continue
                    yystate = 9
                    continue
            case 11:
                yych = yyinput[yycursor]
                if yych <= 0x2F:
                    yystate = 9
                    continue
                if yych >= 0x3A:
                    yystate = 9
                    continue
                yycursor += 1
                yystate = 12
                continue
            case 12:
                yych = yyinput[yycursor]
                if yych <= 0x2F:
                    yystate = 7
                    continue
                if yych <= 0x39:
                    yycursor += 1
                    yystate = 12
                    continue
                yystate = 7
                continue
            case _:
                raise "internal lexer error"


assert lex(b"123\0") == Num.INT
assert lex(b"123.4567\0") == Num.FLOAT
