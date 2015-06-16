<?php
$path_to_theme = "/profiles/ulf/themes/ulftheme/";
?>

<?php include('inc/head.inc') ?>
<title>Search page</title>
</head>
<body>
<div class="page-wrapper js-page-wrapper">
  <div class="page-inner">
    <?php include('inc/header--search.inc') ?>
    <div class="layout-search">
      <div class="layout-inner">
        <div class="layout-element-alpha">
          <div class="layout-element-inner">
            <?php include('snippets/search-module.inc') ?>
            <?php include('snippets/search-facets-content.inc') ?>
            <?php include('snippets/search-module-results-list.inc') ?>
          </div>
        </div>
        <div class="layout-element-beta">
          <div class="layout-element-inner">
            <?php include('snippets/search-facets.inc') ?>
          </div>
        </div>
    </div>
  </div>
</div>
</body>
</html>
