//
//  TMapPathData.h
//  skp
//
//  Created by developer on 12. 8. 19..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import "TMapPoint.h"
#import "TMapPolyLine.h"

typedef enum {
    CAR_PATH,			// 자동차도로
    PEDESTRIAN_PATH,	// 보행자도로
    BICYCLE_PATH,		// 저전거도로
} TMapPathType;

@interface TMapPathData : NSObject

@property (nonatomic, readonly) NSString* errorMessage;

#pragma mark - POI 검색
// https://developers.skplanetx.com/apidoc/kor/t-map/poi/

/*
 *  @abstract
 *      업종 코드를 검색합니다.
 *  @return
 *      BizCategory의 배열.
 *
 */
- (NSArray *)getBizCategory;

/*
 *  @abstract
 *      POI 통합 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *  @param keyword      검색 키워드입니다.
 *
 */
- (NSArray*)requestFindAllPOI:(NSString *)keyword;

/*
 *  @abstract
 *      POI 통합 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *  @param keyword      검색 키워드입니다.
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~99 )
 *
 */
- (NSArray*)requestFindAllPOI:(NSString *)keyword resultCount:(NSInteger)resultCount;

/*
 *  @abstract
 *      POI 명칭 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *
 */
- (NSArray*)requestFindTitlePOI:(NSString*)keyword;

/*
 *  @abstract
 *      POI 명칭 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~99 )
 *
 */
- (NSArray*)requestFindTitlePOI:(NSString*)keyword resultCount:(NSInteger)resultCount;

/*
 *  @abstract
 *      POI 주소 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *
 */
- (NSArray*)requestFindAddressPOI:(NSString*)keyword;

/*
 *  @abstract
 *      POI 주소 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~99 )
 *
 */
- (NSArray*)requestFindAddressPOI:(NSString *)keyword resultCount:(NSInteger)resultCount;

/*
 *  @abstract
 *      카테고리 주변 POI 검색
 *
 *  @discussion
 *      반경을 기준으로 한 카테고리 갬색 주변 POI 검색을 제공합니다.
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param point        반경검색에 사용되는 중심 좌표.
 *  @param categoryName 조회할 업종명칭을 ‘;’ 구분자로 최대 5개까지 입력 가능합니다. - getBizCategory API에서 검색된 middleBizName값.
 *                      단일 업종조회(eg. 주유소) 여러개의 업종조회(eg. 편의점;한식;한의원)
 *  @param radius       반경정보. 1~33의 값을 입력하시면 됩니다. (1=300m 입니다.) 1: 300m, 2: 600m, 3: 900m, 4: 1200m.... 33: 9900m
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~200 )
 *
 */
- (NSArray*)requestFindNameAroundPOI:(TMapPoint*)point categoryName:(NSString *)categoryName radius:(NSInteger)radius resultCount:(NSInteger)resultCount;

/*
 *  @abstract
 *      주변 검색 API - deprecated (사용안함)
 *
 *  @discussion
 *      (2013.06.17 후로 BizCode에 대해서 파라미터로 검색하는 기능을 제공하지 않음) - requestFindNameAroundPOI:로 사용하시기 바랍니다.
 *  @return
 *      nil
 */
- (NSArray*)requestFindGeoPOI:(TMapPoint*)point LCode:(NSString*)classLCode MCode:(NSString*)classMCode;

/*
 *  @abstract
 *      키워드 주변 검색 API
 *
 *  @discussion
 *      반경을 기준으로 한 키워드 검색 주변 POI를 제공합니다.
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param point        반경검색에 사용되는 중심 좌표.
 *  @param keywordName  검색 키워드입니다.
 *  @param radius       반경정보. 0~33의 값을 입력하시면 됩니다. (1=300m 입니다.) 1: 300m, 2: 600m, 3: 900m, 4: 1200m.... 33: 9900m
 *                      “0”: 검색반경을 서버에 위임
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~200 )
 */
- (NSArray*)requestFindAroundKeywordPOI:(TMapPoint*)point keywordName:(NSString *)keywordName radius:(NSInteger)radius resultCount:(NSInteger)resultCount;

# pragma mark - reverseGeoCoding
/*
 * @abstract
 *      Reverse Geocoding
 *
 * @discussion
 *      좌표를 통해 주소정보를 얻습니다.
 *
 * @return 주소정보 (fullAddress)
 * @param tmp 좌표정보
 *
 */
- (NSString*)convertGpsToAddressAt:(TMapPoint*)tmp;

/*
 * @abstract
 *      Reverse Geocoding
 *
 * @discussion
 *      좌표를 통해 주소정보를 얻습니다.
 *
 * @return 주소정보
 * @param tmp 좌표정보
 *
 */
- (NSDictionary*)convertGpsToAddressInfo:(TMapPoint*)tmp;

/*
 * @abstract
 *      Reverse Geocoding
 *
 * @discussion
 *      좌표를 통해 주소정보를 얻습니다.
 *
 * @return 주소정보
 *
 * @param mapPoint 좌표정보
 * @param addressType 주소 타입 (도로명주소: A03, A04)
 *                      A00: 선택한 좌표계에 해당하는 행정동,법정동 주소 입니다.
 *                      A01: 선택한 좌표게에 해당하는 행정동 입니다.     예) 망원2동, 일산1동
 *                      A02: 선택한 좌표계에 해당하는 법정동 주소입니다.  예) 방화동, 목동
 *                      A03: 선택한 좌표계에 해당하는 새주소 길입니다.
 *                      A04: 선택한 좌표계에 해당하는 새주소 건물번호입니다.    예) 양천로 14길 95-11
 *
 */
- (NSDictionary*)reverseGeocoding:(TMapPoint*)mapPoint addressType:(NSString*)type;

#pragma mark - 경로탐색
- (TMapPolyLine *)findPathDataFrom:(TMapPoint*)startPoint to:(TMapPoint*)endPoint;
- (TMapPolyLine *)findPathDataWithType:(TMapPathType)type startPoint:(TMapPoint*)startPoint endPoint:(TMapPoint*)endPoint;
- (NSDictionary*)findPathDataAllWithStartPoint:(TMapPoint*)startPoint endPoint:(TMapPoint*)endPoint;

/*
 * @abstract
 *      타임머신 자동차 길 안내
 *
 * @discussion
 *      출발 혹은 도착시간을 예측한 자동차 길 안내정보를 제공합니다.
 *
 */
- (NSDictionary*)findTimeMachineCarPathWithStartPoint:(TMapPoint*)startPoint        // 출발지
                                             endPoint:(TMapPoint*)endPoint          // 도착지
                                          isStartTime:(BOOL)isStartTime             // 어떤시간을 기준 (YES: 출발시간기준, NO:도착시간 기준)
                                                 time:(NSDate*)date                 // 출발 혹은 도착시간
                                            wayPoints:(NSArray*)wayPoints;          // 경유지 (TMapPint 배열, nil: 경유지 없음)




#pragma mark - 유효성검사
/*
 *  @abstract
 *      ApiKey 유효성 검사
 *
 *  @return         HTTP StatusCode. - 성공:200 (그외 에러 아래 참고)
 *
 *  @discussion
 *      statusCode  ErrorCode   Messages
 *      401         1004        발급되지 않은 BizAppId입니다.
 *      500         1005        시스템 오류입니다.
 *      403         2000        사용할 수 없는 라이브러리 입니다.
 *      400         1100        요청 데이터 오류입니다.
 */
- (NSInteger)validateApiKey:(NSString*)appID;

@end
