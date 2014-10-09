#import <Foundation/Foundation.h>
@import JavaScriptCore;
@protocol KFSExport <JSExport>

JSExportAs(close,            - (NSNumber *)close:(NSNumber*)handle;
JSExportAs(open,             - (NSNumber *)open:(NSString*)fn;

JSExportAs(readSignature,    - (NSString *)readSignature:(NSNumber *)handle pos:(JSValue *)pos);
JSExportAs(readInt32,        - (NSNumber *)readInt32:(NSNumber *)handle pos:(JSValue *)pos);
JSExportAs(readUInt32,       - (NSNumber *)readUInt32:(NSNumber *)handle pos:(JSValue *)pos);
JSExportAs(readUInt8,        - (NSNumber *)readUInt8:(NSNumber *)handle pos:(JSValue *)pos);
JSExportAs(readUTF8String,   - (NSString *)readUInt32:(NSNumber *)handle pos:(JSValue *)pos size:(JSValue *)size);
JSExportAs(readULE16String,  - (NSString *)readUInt32:(NSNumber *)handle pos:(JSValue *)pos size:(JSValue *)size);
JSExportAs(readBuffer,       - (NSArray *)readBuffer:(NSNumber *)handle pos:(JSValue *)pos size:(JSValue *)size);
JSExportAs(readBuf_packedint,- (NSDictionary *)readBuf_packedint:(NSNumber *)handle :pos(JSValue *)pos : size(JSValue *)size : count(JSValue *)count : reset(JSValue *)reset);
JSExportAs(readFixedArray,   - (NSArray *)readFixedArray:(NSNumber *)handle :pos(JSValue *)pos : count(JSValue *)count :unitsz(JSValue *)unitsz);
JSExportAs(readStringArray,  - (NSArray *)readStringArray:(NSNumber *)handle :pos(JSValue *)pos : size(JSValue *)size :enc(JSValue *)enc);

@end  

@interface kfs_ios: KNSObject <KFSExport>
-(void) setRoot : (NSString*)root;
-(void) finalize ;
@end