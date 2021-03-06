#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@import JavaScriptCore;
@protocol KGExport <JSExport>
@property (readonly) NSString *platform;

JSExportAs(log, - (void)log:(NSString*)message);
JSExportAs(debug, - (void)debug:(NSString*)message);
JSExportAs(warn, - (void)warn:(NSString*)message);
JSExportAs(error, - (void)error:(NSString*)message);

JSExportAs(switchApp, - (void)switchApp :(NSString*) app );
JSExportAs(startDownload, -(bool)startDownload:(NSString*) dbid baseurl:(NSString*)baseurl files:(NSString*)files );

- (NSString*)doneDownload ;
- (NSNumber*)downloadedByte ;
- (NSNumber*)downloadingFile ;
- (void)cancelDownload ;
-(NSString*)runtime_version;

@end


@interface ksanagap_ios: NSObject <KGExport, NSURLSessionDataDelegate> {
    
    NSURLSession *session;
    bool downloading;
    UIViewController *vc;
    NSString *downloadresult;
    int downloadedFileCount;
    int64_t downloadedBytes;
    NSMutableArray *downloadedFiles;
    NSMutableArray *downloadingFiles;
    NSMutableArray *tasks;
    
}
- (void)setViewController :(UIViewController*)vc;
-(boolean_t) moveFile :(NSURL*)source target:(NSString*)targetFile;
-(boolean_t) copyFile :(NSURL*)source target:(NSString*)targetFile;
-(NSString *)getFullPath :(NSString*)fn;
-(NSString*)getAppDirectory: (NSString*) appname;

@end
