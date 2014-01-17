//
//  ViewController.m
//  TMapPath
//
//  Created by SDT-1 on 2014. 1. 17..
//  Copyright (c) 2014년 SDT-1. All rights reserved.
//

#import "ViewController.h"
#import "TMapView.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UISegmentedControl *transportType;
@property TMapView *mapView;
@property TMapMarkerItem *startMarker, *endMarker;
@end

@implementation ViewController
- (IBAction)transportChanged:(id)sender {
	[self showPath];
}

- (void)showPath {
	TMapPathData *path = [[TMapPathData alloc] init];
	
	TMapPolyLine *line = [path findPathDataWithType:_transportType.selectedSegmentIndex startPoint:[_startMarker getTMapPoint] endPoint:[_endMarker getTMapPoint]];
	
	if(nil != line) {
		[_mapView showFullPath:@[line]];
		[_mapView bringMarkerToFront:_startMarker];
		[_mapView bringMarkerToFront:_endMarker];
	}
}

- (void)viewDidAppear:(BOOL)animated {
	[self showPath];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
	
	CGRect rect = CGRectMake(0, 44, self.view.frame.size.width, self.view.frame.size.height - 44);
	
	_mapView = [[TMapView alloc] initWithFrame:rect];
	[_mapView setSKPMapApiKey:@"86a2bcf5-5df8-3727-a7b2-55957bfda634"];
	
	[self.view addSubview:_mapView];
	
	_startMarker = [[TMapMarkerItem alloc] init];
	[_startMarker setIcon:[UIImage imageNamed:@"point.png"]];
	TMapPoint *startPoint = [_mapView convertPointToGpsX:50 andY:50];
	[_startMarker setTMapPoint:startPoint];
	[_mapView addCustomObject:_startMarker ID:@"START"];
	
	_endMarker = [[TMapMarkerItem alloc] init];
	[_endMarker setIcon:[UIImage imageNamed:@"point2.png"]];
	TMapPoint *endPoint = [_mapView convertPointToGpsX:300 andY:300];
	[_endMarker setTMapPoint:endPoint];
	[_mapView addCustomObject:_endMarker ID:@"END"];

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
































