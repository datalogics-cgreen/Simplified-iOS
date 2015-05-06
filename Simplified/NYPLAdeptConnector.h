#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wauto-import"

#import <Foundation/Foundation.h>

#pragma clang diagnostic pop

@interface NYPLAdeptConnector : NSObject

@property (atomic, readonly) BOOL deviceAuthorized;

+ (NYPLAdeptConnector *)sharedAdeptConnector;

- (void)authorizeWithVendorID:(NSString *)vendorID
                     username:(NSString *)username
                     password:(NSString *)password;

- (void)deauthorize;

@end
