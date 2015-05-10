<p align="left" >
  <img src="logo.png" alt="KYSelfSizingPushFixCategory" title="KYSelfSizingPushFixCategory">
</p>


![CocoaPods Version](https://img.shields.io/badge/pod-v1.0.0-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Platform](https://img.shields.io/badge/platform-iOS-red.svg)


给UITableViewController增加了一个Category。解决了iOS8中使用Self-Sizing Cell自动布局时，push时发生cell跳跃的bug


#Installation

`pod 'UITableViewController+KYSelfSizingPushFix', '~> 1.0.0'`


##How to use

###三步走：

**1.在`- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath`中，增加：**

```objective-c
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

```objective-c
-(CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [self ky_getEstimatedCellHeightFromCache:indexPath defaultHeight:250.0f];
}
```


**3.使用` [self ky_tableViewReloadData];`替换`[self.tableView reloadData];`**



##*That's it!完美解决！*
