//
//  TMapType.h
//  SKP-Sample
//
//  Created by developer on 12. 9. 21..
//  Copyright (c) 2012년 SKP. All rights reserved.
//
#import <CoreLocation/CoreLocation.h>
typedef enum {
    UNKNOWNTILE,
    NORMALTILE,		// 일반타일 (256x256)
    EXTENSIONTILE,	// 일반타일 확대
    HDTILE          // HD타일 (512x512 이미지)
} TMapTileType;


typedef enum {
    KOREAN,
    ENGLISH,
    CHINESS
} TMapViewLanguage;

typedef enum {
    STANDARD,
    SATELLITE,
    HYBRID,
    TRAFFIC
} TMapViewType;

typedef enum {
    POSITION_DEFAULT,
    POSITION_NAVI
} TMapViewPositionType;
/////////////////////////////////////////////////

typedef enum  {
    TMapUserTrackingModeNone              = 0,
    TMapUserTrackingModeFollow            = 1,
    TMapUserTrackingModeFollowWithHeading = 2
} TMapUserTrackingMode;


typedef struct {
	double latitude;
	double longitude;
} STMapCoordinate;

typedef struct {
    double latitude;
    double longitude;
    int    zoomLevel;
}STMapPointAndLevel;

typedef struct {
    double x;
    double y;
} STMapPoint;

typedef struct {
    double width;
    double height;
} STMapSize;

typedef struct {
    STMapPoint origin;
    STMapSize  size;
} STMapRect;

typedef struct {
	double latitudeDelta;
	double longitudeDelta;
} STMapCoordinateSpan;

typedef double TMapDistance;


extern const STMapSize STMapSizeWorld;

extern const STMapRect STMapRectWorld;

/////

STMapCoordinate STMapCoordinateMake (double latitude, double longitude);

STMapSize STMapSizeMake (double width, double height);

STMapPoint STMapPointMake (double  x, double y);

STMapCoordinateSpan STMapCoordinateSpanMake (double  latitudeDelta, double longitudeDelta);

BOOL TMapCordinateEqualToCoordinate (STMapCoordinate coordinate1, STMapCoordinate coordinate2);

BOOL CordinateEqualToCoordinate (CLLocationCoordinate2D coordinate1, CLLocationCoordinate2D coordinate2);

#pragma mark -
STMapPoint mapPointFromCoordinate2 (CLLocationCoordinate2D coordinate);
STMapPoint mapPointFromCoordinate (CLLocationCoordinate2D coordinate);
CLLocationCoordinate2D coordinateFromMapPoint (STMapPoint point);

STMapPoint meterPointFromCoordinate (CLLocationCoordinate2D coordinate);
STMapPoint meterPointFromCoordinate2 (CLLocationCoordinate2D coordinate);
CLLocationCoordinate2D coordinateFromMeterPoint (STMapPoint point);

// Scale <---> ZoomLevel
NSUInteger TMapZoomLevelFromScale (NSUInteger scale);
NSUInteger TMapScaleFromZoomLevel (NSUInteger zoomLevel);

#pragma mark - Distance
CLLocationDistance getDistance(CLLocationCoordinate2D firstLocation, CLLocationCoordinate2D secondLocation);
BOOL isLocationNearToOtherLocation(CLLocationCoordinate2D firstLocation, CLLocationCoordinate2D secondLocation, CLLocationDistance distanceInGeoCoordinates);


