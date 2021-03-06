///////////////////////////////////////////////////////////////////////////////
// Name:        wx/cocoa/NSButton.h
// Purpose:     wxCocoaNSButton class
// Author:      David Elliott
// Modified by:
// Created:     2002/12/09
// RCS-ID:      $Id: NSButton.h,v 1.6 2004/06/24 15:14:29 DE Exp $
// Copyright:   (c) 2002-2004 David Elliott
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_COCOA_NSBUTTON_H__
#define _WX_COCOA_NSBUTTON_H__

#include "wx/hashmap.h"
#include "wx/cocoa/ObjcAssociate.h"
#include "wx/cocoa/ObjcRef.h"

WX_DECLARE_OBJC_HASHMAP(NSButton);

class wxCocoaNSButton
{
    WX_DECLARE_OBJC_INTERFACE_HASHMAP(NSButton);
public:
    void AssociateNSButton(WX_NSButton cocoaNSButton);
    inline void DisassociateNSButton(WX_NSButton cocoaNSButton)
    {
        if(cocoaNSButton)
            sm_cocoaHash.erase(cocoaNSButton);
    }

    virtual void Cocoa_wxNSButtonAction(void) = 0;
protected:
    static const wxObjcAutoRefFromAlloc<struct objc_object*> sm_cocoaTarget;
};

#endif // _WX_COCOA_NSBUTTON_H__
