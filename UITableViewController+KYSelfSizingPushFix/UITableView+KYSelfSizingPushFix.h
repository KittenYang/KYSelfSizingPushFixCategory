//
//  UITableView+SelfSizingPushFix.h
//
//  Created by Kitten Yang on 4/20/15.
//  Copyright (c) 2015 Kitten Yang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableView (KYSelfSizingPushFix)

/**
 *  第一次,把算出的高度存入字典，key为section-row
 *
 *  @param indexPath 当前indexPath
 *  @param height    存入的高度
 */
- (void) ky_putEstimatedCellHeightToCache:(NSIndexPath *) indexPath height:(CGFloat) height;

/**
 *  取出当前indexPath的高度
 *
 *  @param indexPath     当前indexPath
 *  @param defaultHeight 默认高度
 *
 *  @return 取出的高度
 */
- (CGFloat) ky_getEstimatedCellHeightFromCache:(NSIndexPath *) indexPath defaultHeight:(CGFloat) defaultHeight;

/**
 *  判断字典中是否存在当前indexPath对应的高度
 *
 *  @param indexPath 当前的indexPath
 *
 *  @return 是否存在
 */
- (BOOL) ky_isEstimatedRowHeightInCache:(NSIndexPath *) indexPath;

/**
 *  请用这个方法来刷新tableView取代reloadData
 */
- (void) ky_tableViewReloadData;

@end
