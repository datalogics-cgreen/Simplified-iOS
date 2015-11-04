#import "NYPLReaderRenderer.h"

@class NYPLBook;

@interface NYPLReaderReadiumView : UIView <NYPLReaderRenderer>

@property (nonatomic, weak) id<NYPLReaderRendererDelegate> delegate;
@property (nonatomic, readonly) BOOL isPageTurning;

- (id)init NS_UNAVAILABLE;
- (id)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (id)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame
                         book:(NYPLBook *)book
                     delegate:(id<NYPLReaderRendererDelegate>)delegate;

- (BOOL) bookHasMediaOverlays;
- (BOOL) bookHasMediaOverlaysBeingPlayed;
- (void) applyMediaOverlayPlaybackToggle;
- (void) openPageLeft;
- (void) openPageRight;
@end
