/* --------------------------------------------------------------------------
 *
 * Sample codes for LBKit
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
 * File: helloworld.cpp
 * Description:
 *
 * --------------------------------------------------------------------------*/

#include <lbk/LBKit.h>


class TView : public LBView {
public:
	TView();
	virtual ~TView(); // just for the sample codes

	virtual void		Draw(BRect r);
	virtual void		KeyUp(uint8 key, uint8 clicks);
};


TView::TView()
	: LBView(NULL)
{
}


TView::~TView()
{
}


void
TView::Draw(BRect r)
{
	const char str[] = "Hello world.";

	BPoint pt;
	BRect rect = Bounds();

	SetFontSize(12);
	uint16 w = StringWidth(str);

	pt.x = rect.left + (rect.Width() - w) / 2.f;
	pt.y = rect.top + (rect.Height() - 11) / 2.f;

	DrawString(str, pt);
}


void
TView::KeyUp(uint8 key, uint8 clicks)
{
	Looper()->PostMessage(B_QUIT_REQUESTED);
}


int main(int argc, char **argv)
{
	LBApplication *app = new LBApplication(NULL);

	app->AddPageView(new TView(), false);

	app->Go();

	app->Lock();
	app->Quit();

	return 0;
}

