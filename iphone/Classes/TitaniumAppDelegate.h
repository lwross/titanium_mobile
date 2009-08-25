/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#import <UIKit/UIKit.h>

@class TitaniumViewController, TitaniumHost;


#ifdef MODULE_TI_GESTURE	 	
// thanks to http://stackoverflow.com/questions/150446/how-do-i-detect-when-someone-shakes-an-iphone
static BOOL L0AccelerationIsShaking(UIAcceleration* last, UIAcceleration* current, double threshold) {
	double deltaX = fabs(last.x - current.x), deltaY = fabs(last.y - current.y), deltaZ = fabs(last.z - current.z);
	return
	(deltaX > threshold && deltaY > threshold) ||
	(deltaX > threshold && deltaZ > threshold) ||
	(deltaY > threshold && deltaZ > threshold);
}
#endif

@protocol UIAccelerometerDelegate;


@interface TitaniumAppDelegate : NSObject <UIApplicationDelegate,UIAccelerometerDelegate>
{
    IBOutlet UIWindow *window;
    IBOutlet UIViewController *viewController;
	IBOutlet UIView *loadingView;
	UIView *notificationView;
	NSMutableArray *notifications;

#ifdef MODULE_TI_GESTURE
	BOOL histeresisExcited;
	UIAcceleration * lastAcceleration;
#endif
		
	BOOL abortLaunchingApp;
	BOOL isShowingDialog;
	
	TitaniumHost * currentHost;
}

+ (TitaniumAppDelegate *) sharedDelegate;

- (void)launchTitaniumApp: (NSString *) appPath;
- (BOOL)shouldTakeCareOfUrl:(NSURL *)requestURL useSystemBrowser: (BOOL) useSystemBrowser;

- (void)showLoadingView;
- (void)hideLoadingView;

- (void) accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration;

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UIViewController *viewController;
@property (nonatomic, retain) IBOutlet UIView *loadingView;

#ifdef MODULE_TI_GESTURE
@property (nonatomic, retain)UIAcceleration * lastAcceleration;
#endif

@property (nonatomic, retain)	TitaniumHost * currentHost;
@property (nonatomic, assign)	BOOL isShowingDialog;


@end

