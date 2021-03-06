/* --------------------------------------------------------------------------
 *
 * Simple MPD client using LBKit
 * Copyright (C) 2018, Anthony Lee, All Rights Reserved
 *
 * This software is a freeware; it may be used and distributed according to
 * the terms of The MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * File: IconData.cpp
 * Description:
 *
 * --------------------------------------------------------------------------*/

#include <lbk/LBIconDefs.h>

lbk_icon icon_play = {
LBK_ICON_16x16,{
0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf0,
0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x0f,
0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
}};

lbk_icon icon_pause = {
LBK_ICON_16x16,{
0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00,
0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00,
0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00
}};

lbk_icon icon_next = {
LBK_ICON_16x16,{
0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf0, 0xe0,
0xc0, 0x80, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x0f, 0x07,
0x03, 0x01, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00
}};

lbk_icon icon_prev = {
LBK_ICON_16x16,{
0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x80, 0xc0,
0xe0, 0xf0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x01, 0x03,
0x07, 0x0f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00
}};

