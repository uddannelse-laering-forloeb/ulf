<?php

/**
 * @file
 * Used for search result pages.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
<div class="page-wrapper js-page-wrapper">
  <div class="page-inner">
    <header class="header" role="banner">
      <div class="header--inner">
        <div class="header--nav-wrapper">
          <a href="#" class="nav--toggle-header-search js-toggle-header-search"><img src="/<?php echo $directory; ?>/images/icon-search.png"></a>
          <a href="#" class="nav--toggle-mobile-nav js-toggle-mobile-nav"><img src="/<?php echo $directory; ?>/images/icon-menu.png"></a>
          <?php if ($logo): ?>
            <a class="logo" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
              <img class="logo-image" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
          <?php endif; ?>
        </div>
        <div class="header-search-module js-header-search">
          <div class="header-search-module--inner">
            <?php print render($ulf_search_block['content']); ?>
          </div>
        </div>
      </div>
    </header>
    <nav class="nav--mobile js-mobile-nav">
      <div class="nav--inner">
        <?php if ($main_menu_block) : ?>
          <?php print render($main_menu_block); ?>
        <?php endif; ?>
      </div>
    </nav>
    <nav class="nav">
      <div class="nav--inner">
        <?php if ($main_menu_block) : ?>
          <?php print render($main_menu_block); ?>
        <?php endif; ?>
      </div>
    </nav>
    <?php print $messages; ?>
    <div class="layout-search">
      <div class="layout-inner">
        <div class="layout-element-alpha">
          <div class="layout-element-inner">
            <div class="search-module--form-wrapper">
              <div class="search-module--form">
                <?php print render($page['content']['system_main']['search_form']); ?>
              </div>
              <?php print render($page['content']['system_main']['suggestions']); ?>
              <div class="search-facets-mobile--toggle-wrapper">
                <div href="#" class="search-facets-mobile--toggle js-toggle-mobile-search-facets"><?php print t('Filter Search'); ?></div>
              </div>
            </div>
            <div class="search-facets-mobile js-mobile-search-facets">
              <div class="block-inline-module--content">
                <?php print render($page['content']['facets']); ?>
              </div>
            </div>
            <?php print render($page['content']); ?>
          </div>
        </div>
        <div class="search-module--facets-wrapper layout-element-beta">
          <div class="layout-element-inner">
            <div class="search-facets">
              <h2 class="block-inline-module--header">
                <?php print t('Filter search') ?>
              </h2>
              <div class="block-inline-module--content">
                <?php print render($page['facets']); ?>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <footer class="footer">
      <?php print render($page['footer']); ?>
    </footer>
  </div>
</div>
