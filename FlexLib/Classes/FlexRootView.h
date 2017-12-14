/**
 * Copyright (c) 2017-present, zhenglibao, Inc.
 * email: 798393829@qq.com
 * All rights reserved.
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE file in the root directory of this source tree.
 */



#import <UIKit/UIKit.h>

@class FlexAttr;

@interface UIView(FlexPublic)

// 外部可以主动调用此函数让布局得到刷新
-(void)markDirty;

// 开启关闭布局
-(void)enableFlexLayout:(BOOL)enable;

//
-(BOOL)isFlexLayoutEnable;

// 设置视图属性
-(void)setViewAttr:(NSString*) name
             Value:(NSString*) value;
-(void)setViewAttrs:(NSArray<FlexAttr*>*)attrs;

// 设置布局属性
-(void)setLayoutAttr:(NSString*) name
               Value:(NSString*) value;
-(void)setLayoutAttrs:(NSArray<FlexAttr*>*)attrs;

@end

@interface FlexRootView : UIView

//宽和高是否可变？
@property(nonatomic,assign) BOOL flexibleWidth;
@property(nonatomic,assign) BOOL flexibleHeight;

//四周距离父窗口边界的距离，默认全为0，分水平和竖直两种
@property(nonatomic,assign) UIEdgeInsets portraitSafeArea;
@property(nonatomic,assign) UIEdgeInsets landscapeSafeArea;

//获取xml中的顶级窗口
@property(nonatomic,readonly) UIView* topSubView;

//用于执行layout动画
@property(nonatomic,copy) void (^beginLayout)(void);
@property(nonatomic,copy) void (^endLayout)(void);

//事件通知
@property(nonatomic,copy) void (^onWillLayout)(void);
@property(nonatomic,copy) void (^onDidLayout)(void);

// 从xml文件中加载布局
+(FlexRootView*)loadWithNodeFile:(NSString*)resName
                           Owner:(NSObject*)owner;
// 从data中加载布局
+(FlexRootView*)loadWithNodeData:(NSData*)data
                           Owner:(NSObject*)owner;

-(void)markChildDirty:(UIView*)child;

-(void)registSubView:(UIView*)subView;

-(void)layoutAnimation:(NSTimeInterval)duration;

-(CGSize)calculateSize;

-(CGSize)calculateSize:(CGSize)szLimit;

@end
