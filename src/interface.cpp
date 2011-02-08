/*
 * interface.cpp
 *
 *  Created on: 4 jan. 2011
 *      Author: martijn
 */

/*******************************************************************/
/*																   */
/*						Modules Used							   */
/*																   */
/*******************************************************************/

#include "interface.h"

using namespace std;

/*******************************************************************/
/*																   */
/*					Definitions and macro's						   */
/*																   */
/*******************************************************************/

/*******************************************************************/
/*																   */
/*						Global funtions							   */
/*																   */
/*******************************************************************/

/*******************************************************************/
MainWindow::MainWindow()
/*******************************************************************/
/*
 *
 */
{
	/* scrolling window settings: */
	m_ScrolledWindow.add(m_TreeView);
	m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);	//Only show the scrollbars when they are necessary
	m_refTreeModel = Gtk::TreeStore::create(m_Columns);
	m_TreeView.set_model(m_refTreeModel);
	//m_TreeView.append_column("Convert", m_Columns.m_col_active);
	//m_TreeView.append_column("File", m_Columns.m_col_name);
	Gtk::CellRendererToggle* renderer_active = Gtk::manage( new Gtk::CellRendererToggle());
	renderer_active->signal_toggled().connect( sigc::mem_fun(*this,	&MainWindow::OnRowToggled));
	Gtk::CellRendererText* renderer_name = Gtk::manage( new Gtk::CellRendererText() );
	renderer_name->property_editable() = true;
	//renderer_name->signal_edited().connect( sigc::mem_fun(*this, &ExampleWindow::on_cell_edited))

	/* pack the vertical box */
	add(m_VBox);
	m_VBox.pack_start(m_ScrolledWindow);

	/* Windows settings: */
	set_title("iPhone Backup Converter");
	set_border_width(5);
	set_default_size(800, 480);
	set_position(Gtk::WIN_POS_CENTER);
	//fullscreen();

	Gtk::TreeView::Column* column = Gtk::manage( new Gtk::TreeView::Column("Name") );
	column->pack_start(*renderer_active, false);
	column->pack_start(*renderer_name);
	column->add_attribute(renderer_active->property_active (), m_Columns.m_col_active);
	column->add_attribute(renderer_name->property_text (), m_Columns.m_col_name);

	m_TreeView.append_column(*column);

	//Fill the TreeView's model
	    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	    row[m_Columns.m_col_active] = false;
	    row[m_Columns.m_col_name] = "Billy Bob";

	    Gtk::TreeModel::Row childrow =*(m_refTreeModel->append(row.children()));
	    childrow[m_Columns.m_col_active] = true;
	    childrow[m_Columns.m_col_name] = "Billy Bob Junior";

	    childrow = *(m_refTreeModel->append(row.children()));
	    childrow[m_Columns.m_col_active] = false;
	    childrow[m_Columns.m_col_name] = "Sue Bob";

	    row = *(m_refTreeModel->append());
	    row[m_Columns.m_col_active] = true;
	    row[m_Columns.m_col_name] = "Joey Jojo";

	    row = *(m_refTreeModel->append());
	    row[m_Columns.m_col_active] = true;
	    row[m_Columns.m_col_name] = "Rob McRoberts";

	    childrow = *(m_refTreeModel->append(row.children()));
	    childrow[m_Columns.m_col_active] = false;
	    childrow[m_Columns.m_col_name] = "Xavier McRoberts";

	/* show all widgets: */
	show_all_children();
}

/*******************************************************************/
MainWindow::~MainWindow()
/*******************************************************************/
/*
 * Destructor
 */
{
}

/*******************************************************************/
/*																   */
/*						Local funtions							   */
/*																   */
/*******************************************************************/

/*******************************************************************/
bool MainWindow::FillTree()
/*******************************************************************/
/*
 * Fill the treebox
 */
{
	return true;
}

/*******************************************************************/
void MainWindow::OnRowToggled(const Glib::ustring & path)
/*******************************************************************/
/*
 * Toggle the active state of the row
 */
{
	Gtk::TreeModel::iterator iter = m_refTreeModel->get_iter (path);
	if (iter)
	   (*iter)[m_Columns.m_col_active] = !(*iter)[m_Columns.m_col_active];
}



/*******************************************************************/
/*																   */
/*								EOF								   */
/*																   */
/*******************************************************************/
