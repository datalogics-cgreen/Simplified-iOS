#import "NYPLBookAcquisition.h"
#import "NYPLOPDSEntry.h"

@interface NYPLBook : NSObject

@property (nonatomic, readonly) NYPLBookAcquisition *acquisition;
@property (nonatomic, readonly) NSArray *authorStrings;
@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSURL *imageURL; // nilable
@property (nonatomic, readonly) NSURL *imageThumbnailURL; // nilable
@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSDate *updated;

+ (NYPLBook *)bookWithEntry:(NYPLOPDSEntry *)entry;

// designated initializer
- (instancetype)initWithAcquisition:(NYPLBookAcquisition *)acquisition
                      authorStrings:(NSArray *)authorStrings
                         identifier:(NSString *)identifier
                           imageURL:(NSURL *)imageURL
                  imageThumbnailURL:(NSURL *)imageThumbnailURL
                              title:(NSString *)title
                            updated:(NSDate *)updated;

@end