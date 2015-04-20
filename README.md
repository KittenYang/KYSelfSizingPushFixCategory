# KYSelfSizingPushFixCategory
给UITableViewController增加了一个Category。解决了iOS8中使用Self-Sizing Cell自动布局时，push时发生cell跳跃的bug

##How to use

###三步走：

**1.在`- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath`中，增加：**
```
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    ...
    
    if (![self ky_isEstimatedRowHeightInCache:indexPath]) {
        CGSize cellSize = [cell systemLayoutSizeFittingSize:CGSizeMake(self.view.frame.size.width, 0) withHorizontalFittingPriority:1000.0 verticalFittingPriority:50.0];
        [self ky_putEstimatedCellHeightToCache:indexPath height:cellSize.height];
    }
    
    ...

}
```

**2.实现`estimatedHeightForRowAtIndexPath:`这个方法：**
```
-(CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [self ky_getEstimatedCellHeightFromCache:indexPath defaultHeight:250.0f];
}
```


**3.使用` [self ky_tableViewReloadData];`替换`[self.tableView reloadData];`**



##*That's it!完美解决！*
