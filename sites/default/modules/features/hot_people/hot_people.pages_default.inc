<?php
/**
 * @file
 * hot_people.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hot_people_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'leadership';
  $page->task = 'page';
  $page->admin_title = 'leadership';
  $page->admin_description = '';
  $page->path = 'leadership/board';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Board',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_leadership_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'leadership';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'leadership',
    'css_id' => 'leadership',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Leadership';
  $display->uuid = '1cd88d5d-93a4-4202-9fb5-8b831ced9da1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3235225a-2fa8-4ad9-b9a4-97a6ab086182';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'leadership-panel_pane_board';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3235225a-2fa8-4ad9-b9a4-97a6ab086182';
    $display->content['new-3235225a-2fa8-4ad9-b9a4-97a6ab086182'] = $pane;
    $display->panels['middle'][0] = 'new-3235225a-2fa8-4ad9-b9a4-97a6ab086182';
    $pane = new stdClass();
    $pane->pid = 'new-46e42b47-4c75-44c8-b205-057bff7d4f00';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'leadership-panel_pane_director';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '46e42b47-4c75-44c8-b205-057bff7d4f00';
    $display->content['new-46e42b47-4c75-44c8-b205-057bff7d4f00'] = $pane;
    $display->panels['middle'][1] = 'new-46e42b47-4c75-44c8-b205-057bff7d4f00';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3235225a-2fa8-4ad9-b9a4-97a6ab086182';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['leadership'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'voting_members';
  $page->task = 'page';
  $page->admin_title = 'Voting members';
  $page->admin_description = '';
  $page->path = 'leadership/voting-members';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_voting_members__panel_context_9c1e955c-0605-4cdb-9085-df37f2e0b798';
  $handler->task = 'page';
  $handler->subtask = 'voting_members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Voting members';
  $display->uuid = '29cf1d2c-b917-4f0d-904a-cae1d553561d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3386041d-3e34-492e-879a-1ad570976997';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Member intro',
      'title' => '',
      'body' => '<p style="color: #333333; font-family: \'Open Sans\', Arial, Helvetica, sans-serif; font-size: 12px; line-height: 20px;">Anyone and everyone can get involved in HOT activities, and we have a wonderful community of people who do so, by helping with remote mapping initiatives and also things like technical development work and promotional work. You can all regard yourselves as part of the&nbsp;<a style="color: #d40000;" title="Humanitarian OpenStreetMap Team" href="http://wiki.openstreetmap.org/wiki/Humanitarian_OpenStreetMap_Team">Humanitarian OpenStreetMap Team</a>!</p><p style="color: #333333; font-family: \'Open Sans\', Arial, Helvetica, sans-serif; font-size: 12px; line-height: 20px;">We have a concept of "members" as part of the&nbsp;<a style="color: #d40000;" title="Humanitarian OSM Team/U.S. Articles of Incorporation" href="http://wiki.openstreetmap.org/wiki/Humanitarian_OSM_Team/U.S._Articles_of_Incorporation">Humanitarian OSM Team/U.S. Articles of Incorporation</a>. HOT members are allowed to nominate new people to become members. Nominations take place periodically (not a constant rolling programme). HOT members can also stand for, and vote in&nbsp;<a style="color: #d40000;" title="Humanitarian OSM Team/Board Elections" href="http://wiki.openstreetmap.org/wiki/Humanitarian_OSM_Team/Board_Elections">Humanitarian OSM Team/Board Elections</a>. We can think of these people as a selected "core team". Many of them have been deployed in the field doing work for HOT.</p>',
      'format' => '1',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3386041d-3e34-492e-879a-1ad570976997';
    $display->content['new-3386041d-3e34-492e-879a-1ad570976997'] = $pane;
    $display->panels['middle'][0] = 'new-3386041d-3e34-492e-879a-1ad570976997';
    $pane = new stdClass();
    $pane->pid = 'new-ceb0423e-60b9-4131-98fe-7686875025ef';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_lists-panel_pane_members_voting';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ceb0423e-60b9-4131-98fe-7686875025ef';
    $display->content['new-ceb0423e-60b9-4131-98fe-7686875025ef'] = $pane;
    $display->panels['middle'][1] = 'new-ceb0423e-60b9-4131-98fe-7686875025ef';
    $pane = new stdClass();
    $pane->pid = 'new-fe2dc7ad-ec5c-48e9-879b-154a38268d8b';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Members text list',
      'title' => '',
      'body' => '<p style="color: #333333; font-family: \'Open Sans\', Arial, Helvetica, sans-serif; font-size: 12px; line-height: 20px;">This list has been updated to reflect official changes in voting membership in December 2012, January 2013, February 2014, February 2015 and April 2015.</p><ul style="color: #333333; font-family: \'Open Sans\', Arial, Helvetica, sans-serif; font-size: 12px; line-height: 20px;"><li>Aaron Cope</li><li><span data-sheets-value="[null,2,&quot;ALCE Samuel Paul&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">ALCE Samuel Paul</span></li><li>Amadou Ndong</li><li>Andrew Buck</li><li>Andrew Turner</li><li>Augustin Doury</li><li>Awa Laye Dia</li><li><span data-sheets-value="[null,2,&quot;BAGNOUMANA Bazo FOFANA&quot;]" data-sheets-userformat="[null,null,12801,[null,0],null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">BAGNOUMANA Bazo FOFANA</span></li><li><span data-sheets-value="[null,2,&quot;Ben Abelshausen&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Ben Abelshausen</span></li><li>Besfort Guri</li><li><span data-sheets-value="[null,2,&quot;BOUKPESSI Bital\\u00e9&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">BOUKPESSI Bitalé</span></li><li>Boris Mogwitz</li><li>Brian Wolford</li><li>Chris Blow</li><li>Claire Halleux</li><li>Dale Kunce</li><li><span data-sheets-value="[null,2,&quot;Dan Joseph&quot;]" data-sheets-userformat="[null,null,12801,[null,0],null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Dan Joseph</span></li><li>Dane Springmeyer</li><li><span data-sheets-value="[null,2,&quot;Delphine Bedu&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Delphine Bedu</span></li><li><span data-sheets-value="[null,2,&quot;Dra\\u017een Odoba\\u0161i\\u0107&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Dražen Odobašić</span></li><li>Emir Hartato</li><li>Eugene Usvitsky</li><li><span data-sheets-value="[null,2,&quot;Felix Delattre&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Felix Delattre</span></li><li><span data-sheets-value="[null,2,&quot;Francis Patrick Boon&quot;]" data-sheets-userformat="[null,null,12801,[null,0],null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Francis Patrick Boon</span></li><li>François-Xavier Lamure Tardieu</li><li>Frederic Bonifas</li><li>Frederic Moine</li><li><span data-sheets-value="[null,2,&quot;GIRAUD Pierre&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">GIRAUD Pierre</span></li><li>Hameed Tasal</li><li>Harry Wood</li><li>Heather Leson</li><li>Humberto Yances</li><li><span data-sheets-value="[null,2,&quot;Ismaila SEYE&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">Ismaila SEYE</span></li><li>Ivan Sanchez Ortega</li><li>Jaakko Helleranta</li><li><span data-sheets-value="[null,2,&quot;James Blake Girardot&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">James Blake Girardot</span></li><li><span data-sheets-value="[null,2,&quot;Jean Marie MANCABOU&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">Jean Marie MANCABOU</span></li><li>Jean-Guilhem Cailton</li><li>Jeff Haack</li><li>John Crowley</li><li>Jorieke Vyncke</li><li>Joseph Reeves</li><li>Julio Costa Zambelli</li><li>Kate Chapman</li><li>Katie Filbert</li><li>Leonard Doyle</li><li>Lisa Sweeney</li><li><span data-sheets-value="[null,2,&quot;Louino Robillard&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">Louino Robillard</span></li><li>Mamadou bassirou THIAM</li><li><span data-sheets-value="[null,2,&quot;Maning Sambale&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">Maning Sambale</span></li><li>Mikel Maron</li><li><span data-sheets-value="[null,2,&quot;Nama Raj Budhathoki&quot;]" data-sheets-userformat="[null,null,12801,[null,0],null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Nama Raj Budhathoki</span></li><li><span data-sheets-value="[null,2,&quot;Nicholas George Allen&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">Nicholas George Allen</span></li><li>Nicolas Chavent</li><li><span data-sheets-value="[null,2,&quot;Nuala Cowan&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Nuala Cowan</span></li><li><span data-sheets-value="[null,2,&quot;Orsolya Jenei&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Orsolya Jenei</span></li><li><span data-sheets-value="[null,2,&quot;Pete Masters&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Pete Masters</span></li><li>Pierre Beland</li><li>Rafael Ávila Coya</li><li>Rob Baker</li><li>Robert Banick</li><li>Robert Soden</li><li>Roderick Bera</li><li>Russell Deffner</li><li>Sam Larsen</li><li><span data-sheets-value="[null,2,&quot;Satoshi IIDA&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Satoshi IIDA</span></li><li>Schuyler Erle</li><li>Sebastien Pierrel</li><li>Severin Menard</li><li><span data-sheets-value="[null,2,&quot;Shoaib Burq&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Shoaib Burq</span></li><li>Shu Higashi</li><li>Stéphane Henriod</li><li><span data-sheets-value="[null,2,&quot;T. Suha \\u00dclgen&quot;]" data-sheets-userformat="[null,null,12801,[null,0],null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">T. Suha Ülgen</span></li><li><span data-sheets-value="[null,2,&quot;Taichi Furuhashi&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Taichi Furuhashi</span></li><li>Tim McNamara</li><li>Tim Waters</li><li>Todd Huffman</li><li>Tom Buckley</li><li>Trevor Ellermann</li><li><span data-sheets-value="[null,2,&quot;Vasanthi Hargyono&quot;]" data-sheets-userformat="[null,null,513,[null,0],null,null,null,null,null,null,null,null,0]">Vasanthi Hargyono</span></li><li><span data-sheets-value="[null,2,&quot;Vitor George&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Vitor George</span></li><li><span data-sheets-value="[null,2,&quot;Vivien Deparday&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Vivien Deparday</span></li><li>Will Skora</li><li><span data-sheets-value="[null,2,&quot;Yantisa Akhadi&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Yantisa Akhadi</span></li><li>Yohan Boniface</li><li><span data-sheets-value="[null,2,&quot;Zacharia Muindi&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Zacharia Muindi</span></li></ul><p style="color: #333333; font-family: \'Open Sans\', Arial, Helvetica, sans-serif; font-size: 12px; line-height: 20px;">Alumni</p><ul style="color: #333333; font-family: \'Open Sans\', Arial, Helvetica, sans-serif; font-size: 12px; line-height: 20.0063037872314px;"><li>Anna Hodgkinson</li><li><span data-sheets-value="[null,2,&quot;Mark Cupitt&quot;]" data-sheets-userformat="[null,null,12800,null,null,null,null,null,null,null,null,null,0,null,null,&quot;arial,sans,sans-serif&quot;,10]">Mark Cupitt</span></li></ul>',
      'format' => '1',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'fe2dc7ad-ec5c-48e9-879b-154a38268d8b';
    $display->content['new-fe2dc7ad-ec5c-48e9-879b-154a38268d8b'] = $pane;
    $display->panels['middle'][2] = 'new-fe2dc7ad-ec5c-48e9-879b-154a38268d8b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['voting_members'] = $page;

  return $pages;

}
