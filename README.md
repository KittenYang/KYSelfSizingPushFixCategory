<p align="left" >
  <img src="logo.png" alt="KYSelfSizingPushFixCategory" title="KYSelfSizingPushFixCategory">
</p>


![CocoaPods Version](https://img.shields.io/badge/pod-v1.0.0-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Platform](https://img.shields.io/badge/platform-iOS-red.svg)



Fix the bug of 'Self-Sizing-Cell' when push to next ViewController the tableView position will change.


#Installation

`pod 'UITableViewController+KYSelfSizingPushFix', '~> 1.0.0'`


##How to use

###Three Steps：

**1.Add code in `- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath`**

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

**2.Implement `estimatedHeightForRowAtIndexPath:`：**

```objective-c
-(CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [self ky_getEstimatedCellHeightFromCache:indexPath defaultHeight:250.0f];
}
```


**3.Remember to use` [self ky_tableViewReloadData];` rather than `[self.tableView reloadData];`**



##*You're done!*
