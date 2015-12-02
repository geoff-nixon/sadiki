/*
        NSPDFPanel.h
        Application Kit
        Copyright (c) 2013, Apple Inc.
        All rights reserved.
*/

#import <Foundation/NSObject.h>

@class NSMutableArray, NSString;
@class NSPDFInfo, NSViewController, NSWindow;

typedef NS_OPTIONS(NSInteger, NSPDFPanelOptions) {
    NSPDFPanelShowsPaperSize = 1 << 2,
    NSPDFPanelShowsOrientation = 1 << 3,
    NSPDFPanelRequestsParentDirectory = 1 << 24
} NS_ENUM_AVAILABLE_MAC(10_9);

NS_CLASS_AVAILABLE_MAC(10_9)
@interface NSPDFPanel : NSObject {
    NSViewController *_accessoryController;
    NSPDFPanelOptions _options;
    NSString *_defaultFileName;
    id _panel;
    id _private;
};

/* Create a new NSPDFPanel.
*/
+ (NSPDFPanel *)panel;

/* Controller for the accessory views that will be presented in the panel by the methods below. When the panel is presented to the user the controller is automatically sent a -setRepresentedObject: message with an NSPDFInfo equivalent to those one passed to -beginSheetWithPDFInfo:modalForWindow:completionHandler:.
*/
@property (retain) NSViewController *accessoryController;

/* The options described above. The default value is 0. To allow your application to take advantage of controls that may be added by default in future versions OS X, get the options from the panel you've just created, turn on and off the flags you care about, and then set the options.
*/
@property NSPDFPanelOptions options;

/*  The user-editable file name shown in the name field. The default value is the equivalent of 'Untitled' for the current locale. Note that this string should never include a file extension.
*/
@property (copy) NSString *defaultFileName;

/* Present a print panel to the user, document-modally. When the user has dismissed it, invoke the completionHandler block. If the user didn't click the 'Cancel' button, the given NSPDFInfo will be modified to reflect the user's chosen settings, if any.
 */
#if NS_BLOCKS_AVAILABLE
- (void)beginSheetWithPDFInfo:(NSPDFInfo *)pdfInfo modalForWindow:(NSWindow *)docWindow completionHandler:(void (^)(NSInteger))completionHandler;
#endif
@end
