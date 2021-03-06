/* --------------------------------------------------------------------------
 *
 * Little Board Application Kit
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
 * File: LBMenuItem.cpp
 * Description:
 *
 * --------------------------------------------------------------------------*/

#include <string.h>
#include <lbk/LBMenuItem.h>
#include <lbk/LBMenuView.h>

#define ICON_IS_32x32(id)	((id) > LBK_ICON_ID_32x32_BEGIN && (id) < LBK_ICON_ID_32x32_END)


LBMenuItem::LBMenuItem(const char *label,
		       BMessage *message,
		       lbk_icon_id idIcon)
	: LBScopeItem(),
	  BInvoker(message, NULL),
	  fLabel(NULL),
	  fIcon(LBK_ICON_NONE),
	  fIconData(NULL)
{
	SetLabel(label);
	SetIcon(idIcon);
}


LBMenuItem::LBMenuItem(const char *label,
		       BMessage *message,
		       const lbk_icon *icon)
	: LBScopeItem(),
	  BInvoker(message, NULL),
	  fLabel(NULL),
	  fIcon(LBK_ICON_NONE),
	  fIconData(NULL)
{
	SetLabel(label);
	SetIcon(icon);
}


LBMenuItem::~LBMenuItem()
{
	if(fLabel != NULL) free(fLabel);
}


const char*
LBMenuItem::Label() const
{
	return fLabel;
}


void
LBMenuItem::SetLabel(const char *label)
{
	if(fLabel != NULL) free(fLabel);
	fLabel = (label != NULL ? strdup(label) : NULL);

	if(IsVisible() == false) return;

	LBMenuView *view = e_cast_as(ScopeHandler(), LBMenuView);
	if(view == NULL || view->IsActivated() == false || view->CurrentSelection() != this) return;

	BRect r = view->ItemLabelBounds();
	view->Invalidate(r);
}


lbk_icon_id
LBMenuItem::Icon() const
{
	return fIcon;
}


const lbk_icon*
LBMenuItem::IconData() const
{
	return((fIconData != NULL) ? fIconData : lbk_get_icon_data(fIcon));
}


void
LBMenuItem::SetIcon(lbk_icon_id idIcon)
{
	// only 32x32
	fIcon = (ICON_IS_32x32(idIcon) ? idIcon : LBK_ICON_NONE);
	fIconData = NULL;

	if(IsVisible() == false) return;

	LBMenuView *view = e_cast_as(ScopeHandler(), LBMenuView);
	if(view == NULL || view->IsActivated() == false) return;

	BRect r = view->ItemIconBounds();
	view->Invalidate(r);
}


void
LBMenuItem::SetIcon(const lbk_icon *icon)
{
	fIcon = LBK_ICON_NONE;
	fIconData = icon;

	if(IsVisible() == false) return;

	LBMenuView *view = e_cast_as(ScopeHandler(), LBMenuView);
	if(view == NULL || view->IsActivated() == false) return;

	BRect r = view->ItemIconBounds();
	view->Invalidate(r);
}


bool
LBMenuItem::IsHidden() const
{
	return(!IsVisible());
}


void
LBMenuItem::DrawLabel(LBView *view, BRect r)
{
	if(fLabel == NULL) return;

	view->SetFontSize(12);
	BPoint loc(r.left + r.Width() / 2.f - (float)view->StringWidth(fLabel) / 2.f, r.top + 1.f);
	view->DrawString(fLabel, loc);
}


void
LBMenuItem::DrawIcon(LBView *view, BRect r)
{
	BPoint loc = r.LeftTop() + BPoint(r.Width() / 2.f, r.Height() / 2.f) - BPoint(15, 15);

	if(fIconData != NULL)
		view->DrawIcon(fIconData, loc);
	else
		view->DrawIcon(fIcon, loc);
}


#ifndef ETK_MAJOR_VERSION
status_t
LBMenuItem::Invoke(const BMessage *msg)
{
	BMessage *message = const_cast<BMessage*>(msg);
	return BInvoker::Invoke(message);
}
#endif

